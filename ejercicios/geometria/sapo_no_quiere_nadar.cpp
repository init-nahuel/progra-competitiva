#include <bits/stdc++.h>
using namespace std;

template <class T> // T es el parámetro de tipo
struct Point{
	T x, y; // ahora x, y son de tipo T
	Point(T _x=0, T _y=0) : x(_x), y(_y) {}
	// Suma y resta
	Point operator+(Point p) const { return Point(x+p.x, y+p.y); }
	Point operator-(Point p) const { return Point(x-p.x, y-p.y); }
	// Multiplicación y división coordenada a coordenada
	Point operator*(Point p) const { return Point(x*p.x, y*p.y); }
	Point operator/(Point p) const { return Point(x/p.x, y/p.y); }
	// Menor e igualdad. Usamos tie que retorna una tupla (y por ende compara en orden de izq. a der.)
	bool operator<(Point p) const { return tie(x,y) < tie(p.x, p.y); }
	bool operator==(Point p) const { return tie(x,y) == tie(p.x, p.y); }
	// De acá en adelante los métodos interpretan al punto como un vector
	// dist2 retorna el largo al cuadrado. Siempre es mejor usarla al cuadrado cuando sea posible para evitar usar doubles
	T dist2() const { return x*x + y*y; }
	long double dist() const { return sqrtl(dist2()); }
	// dot retorna el producto punto con otro vector.
	T dot(Point p) const { return x*p.x + y*p.y; }
	// cross retorna la tercera coordenada del producto cruz
	T cross(Point p) const { return x*p.y - y*p.x; }
	// unit retorna el vector normalizado (largo 1)
	Point unit() const { return *this/dist(); }
	// perp obtiene un vector perpendicular, es decir rota en +90 grados
	Point perp() const { return Point(-y, x); }
	// normal retorna un vector normal unitario
	Point normal() const { return perp().unit(); }

	// Además se puede hacer overload de operadores ">>" y "<<" para que poder leer/imprimir Point con cin/cout
	friend istream& operator>>(istream& is, Point &p){
		return is >> p.x >> p.y;
	}
	friend ostream& operator<<(ostream& os, const Point &p) {
		return os << "(" << p.x << "," << p.y << ")";
	}
};

/* Retorna -1, 0 o 1 dependiendo del sentido de giro de b a c partiendo de a.
 * Es decir, iniciando en "a" mirando a "b", evalúa el sentido de giro al moverse hasta "c".
 * Otra forma de decirlo es: hacia qué sentido gira el vector bc al ponerlo después del vector ab
 */
template <typename T>
int orientation(Point <T> a, Point <T> b, Point <T> c){
	T v = (b-a).cross(c-b);
	if(v < 0) return -1; // sentido horario
	if(v > 0) return +1; // sentido anti-horario
	return 0; // colineales
}

// Código de Convex Hull. Adaptado de https://cp-algorithms.com/geometry/convex-hull.html#implementation
template <typename T>
vector <Point<T>> convex_hull(vector <Point<T>>& pts){
	// Primero buscamos el punto de menor coordenada p0.
	Point <T> p0 = *min_element(pts.begin(), pts.end());
	// Luego, ordenamos el resto de los puntos según su ángulo con p0.
	sort(pts.begin(), pts.end(), [&p0](const Point<T> &a, const Point<T> &b){
			int o = orientation(p0, a, b);
			if(o == 0){
				return (a-p0).dist() < (b-p0).dist();
			}
			return o > 0;
	});

	// Finalmente, armamos el convex hull.
	vector <Point<T>> hull;
	for(int i=0; i<(int)pts.size(); i++){
		// Descartamos los puntos que hagan un giro en sentido horario.
		while(hull.size() > 1 && orientation(hull[hull.size()-2], hull.back(), pts[i]) <= 0){
			hull.pop_back();
		}
		hull.push_back(pts[i]);
	}
	return hull;
}

long double distance(vector<Point<int>> points) {
    long double dist = 0;
    if (points.size() == 1) dist;
    auto first_point = points.begin(), second_point = points.begin() + 1;
    while (second_point != points.end()) {
        dist += (*second_point - *first_point).dist();
        first_point += 1; second_point += 1;
    }
    return dist;
}

int main() {
    int n; cin >> n;
    vector <Point<int>> vertexs;
    vector <Point<int>> union_all;
    for (int i=0; i<n; i++) {
        Point<int> p;
        int x, y; cin >> x >> y;
        p.x = x; p.y = y;
        vertexs.push_back(p);
        union_all.push_back(p);
    }
    int x, y; cin >> x >> y;
    Point<int> s_loc = Point(x, y);
    cin >> x >> y;
    Point<int> t_loc = Point(x, y);

    union_all.push_back(s_loc); union_all.push_back(t_loc);
    
    vector <Point<int>> convex_hull_vector = convex_hull(union_all);
    auto s_it = find(convex_hull_vector.begin(), convex_hull_vector.end(), s_loc);
    auto t_it = find(convex_hull_vector.begin(), convex_hull_vector.end(), t_loc);
    long double dist = 0;
    
    if (s_it != convex_hull_vector.end() && t_it != convex_hull_vector.end()) {
        long double normal_path = 0, reverse_path = 0;

        if (s_it < t_it) {
            vector <Point<int>> normal_path_vector(s_it, t_it), first_slice(convex_hull_vector.begin(), s_it), second_slice(t_it, convex_hull_vector.end());
            if (s_it == convex_hull_vector.begin()) first_slice = {*s_it};
            // if (t_it == convex_hull_vector.end()) second_slice = {*t_it};
            normal_path = distance(normal_path_vector);
            reverse_path = distance(first_slice); reverse_path += distance(second_slice);
        }
        else {
            vector <Point<int>> normal_path_vector(t_it, s_it), first_slice(convex_hull_vector.begin(), t_it), second_slice(s_it, convex_hull_vector.end());
            // if (s_it == convex_hull_vector.end()) first_slice = {*s_it};
            if (t_it == convex_hull_vector.begin()) second_slice = {*t_it};
            normal_path = distance(normal_path_vector);
            reverse_path = distance(first_slice); reverse_path += distance(second_slice);
        }
        
        if (reverse_path == 0) dist = normal_path;
        else dist = min(normal_path, reverse_path);
    }
    else {
        dist = (s_loc - t_loc).dist();
    }

    cout << fixed << setprecision(9) << dist << "\n";

    return 0;
}
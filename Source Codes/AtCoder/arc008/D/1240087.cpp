#include <cstdio>
#include <cstdlib>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

template <class T>
class segment_tree {
    public:
    segment_tree(int n, function<T(const T&, const T&)> func, const T& init = T());
    segment_tree(T* array, int n, function<T(const T&, const T&)> func, const T& init = T());
    ~segment_tree();
    void add(int x, const T& value);
    void update(int x, const T& value);
    T get(int x, int y); // [x, y)
    
    private:
    int size;
    function<T(const T&, const T&)> func;
    T init;
    T* data;
};

template <class T> segment_tree<T>::segment_tree(int n, function<T(const T&, const T&)> func, const T& init) : size(1 << (32 - __builtin_clz(n - 1))), func(func), init(init) {
    data = (T *)malloc(sizeof(T) * size * 2);
    for (int i = 0; i < size * 2; i++) data[i] = init;
}

template <class T> segment_tree<T>::segment_tree(T* array, int n, function<T(const T&, const T&)> func, const T& init) : segment_tree(n, func, init) {
    for (int i = 0; i < n; i++) data[size + i] = array[i];
    for (int i = size - 1; i > 0; i--) data[i] = func(data[i * 2], data[i * 2 + 1]);
}

template <class T> segment_tree<T>::~segment_tree() {
    free(data);
}

template <class T> void segment_tree<T>::add(int x, const T& value) {
    x += size;
    data[x] += value;
    while (x > 1) {
        x >>= 1;
        data[x] = func(data[x * 2], data[x * 2 + 1]);
    }
}

template <class T> void segment_tree<T>::update(int x, const T& value) {
    x += size;
    data[x] = value;
    while (x > 1) {
        x >>= 1;
        data[x] = func(data[x * 2], data[x * 2 + 1]);
    }
}

template <class T> T segment_tree<T>::get(int x, int y) {
    T vl = init, vr = init;
    for (x += size, y += size; x < y; x >>= 1, y >>= 1) {
        if (x & 1) vl = func(vl, data[x++]);
        if (y & 1) vr = func(data[--y], vr);
    }
    return func(vl, vr);
}

long long p[100000];
double a[100000];
double b[100000];

int main() {
    int m, i;
    long long n;
    double ans1 = 1, ans2 = 1;
    vector <long long> v;
    
    scanf("%lld %d", &n, &m);
    
    for (i = 0; i < m; i++) scanf("%lld %lf %lf", &p[i], &a[i], &b[i]);
    
    for (i = 0; i < m; i++) v.push_back(p[i]);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    segment_tree<pair<double, double> > s(v.size(), [](const pair<double, double>& x, const pair<double, double>& y) { return make_pair(x.first * y.first, x.second * y.first + y.second); }, make_pair(1, 0));
    
    for (i = 0; i < m; i++) {
        int x = lower_bound(v.begin(), v.end(), p[i]) - v.begin();
        pair <double, double> t;
        
        s.update(x, make_pair(a[i], b[i]));
        t = s.get(0, v.size());
        ans1 = min(ans1, t.first + t.second);
        ans2 = max(ans2, t.first + t.second);
    }
    
    printf("%.12lf\n", ans1);
    printf("%.12lf\n", ans2);
    
    return 0;
}
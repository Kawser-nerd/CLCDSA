#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>


constexpr double PI = 3.14159265359;


class Cone {
private:
    int m_x_bottom;
    int m_x_top;
    int m_height;
    int m_radius;
    double m_slope;
public:
    Cone(const int& x_bottom, const int& height, const int& radius) {
        m_x_bottom = x_bottom;
        m_x_top = x_bottom + height;
        m_height = height;
        m_radius = radius;
        m_slope = (double)radius / (double)height;
    }
    double compute_volume(const int& a, const int& b) {
        if (m_x_bottom >= b || m_x_top <= a)
        {
            return 0.0;
        }
        int x_high = std::min(m_x_top, b);
        int x_low = std::max(m_x_bottom, a);
        double s = (double)(m_x_top - x_high) * m_slope;
        double r = (double)(m_x_top - x_low) * m_slope;
        double v = PI * (r * r + r * s + s * s) * (x_high - x_low) / 3.0;
        return v;
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<Cone> cones;
    for (auto i = 0; i < n; i++)
    {
        int x_bottom, radius, height;
        std::cin >> x_bottom >> radius >> height;
        Cone cone(x_bottom, height, radius);
        cones.push_back(cone);
    }
    std::cout << std::setprecision(8) << std::fixed;
    for (auto j = 0; j < q; j++) {
        int a, b;
        std::cin >> a >> b;
        double v = 0.0;
        for (auto& cone : cones) {
            v += cone.compute_volume(a, b);
        }
        std::cout << v << std::endl;
    }
    return EXIT_SUCCESS;
}
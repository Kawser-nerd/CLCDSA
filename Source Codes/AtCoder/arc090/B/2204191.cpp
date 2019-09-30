#include<iostream>
#include <vector>
class Coordinate {
	struct Relation {
		Coordinate *origin{ nullptr };
		int distance{ 0 };
		Relation() {};
		Relation(Coordinate* o, int dist) :origin{ o }, distance{ dist } {}
	};
	Relation origin;
	enum class Coordinate_type :bool {
		origin = true, relational = false
	};
	Coordinate_type c_type{ Coordinate_type::origin };
	bool is_non_paradoxical(Coordinate &other, int distance) {
		auto this_relation = relation();
		auto other_relation = other.relation();
		if (this_relation.origin != other_relation.origin) return true;
		else return this_relation.distance == other_relation.distance + distance;
	}
	Relation relation() {
		switch (c_type) {
		case Coordinate_type::origin: return Relation{ this, 0 };
		case Coordinate_type::relational:
			auto prev = origin.origin->relation();
			return origin = Relation(prev.origin, origin.distance + prev.distance);
		}
	}
public:
	Coordinate() {}
	bool set_relation(Coordinate &other, int distance) {
		if (is_non_paradoxical(other, distance)) {
			if (relation().origin == other.relation().origin) return true;
			switch (c_type) {
			case Coordinate_type::origin:
				origin = Relation(&other, distance);
				c_type = Coordinate_type::relational;
				break;
			case Coordinate_type::relational:
				origin.origin->set_relation(other, distance - origin.distance);
				break;
			}
			return true;
		}
		else return false;
	}
};
int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<Coordinate> peoples(n);
	bool is_paradoxical{ false };
	{
		int l, r, d;
		for (auto i = 0; i < m && !is_paradoxical; ++i) {
			std::cin >> l >> r >> d;
			if (!peoples[l - 1].set_relation(peoples[r - 1], d)) {
				is_paradoxical = true;
			}
		}
	}
	if (is_paradoxical) std::cout << "No" << std::endl;
	else std::cout << "Yes" << std::endl;
}
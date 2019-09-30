#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<set>
#include<map>
#include<fstream>
#define epsilon 0.000000001 
#define epsilon2 0.00000001 
using namespace std;
#define cosinusa(a, b, c) ((a * a + b * b - c * c) / (2.0 * a * b));


bool isnula(double d)
{
	return fabs(d) < epsilon;
}

bool equal(double a, double b)
{
	return isnula(a - b);
}

//Square equation
class Equation
{
public:
	Equation(double a1, double b1, double c1): a(a1), b(b1), c(c1){};
	vector<double> solutions()const;
	double a, b, c;
};
vector<double> Equation::solutions()const
{
	vector<double> toRet;
	if(isnula(a))
	{
		if(isnula(b))
			return toRet;
		toRet.push_back(-c / b);
		return toRet;
	}
	double D = b * b - 4.0 * a * c;
	if(isnula(D))
	{
		toRet.push_back(-b / (2.0 * a));
		return toRet;
	}
	if(D < 0)
		return toRet;
	D = sqrt(D);
	toRet.push_back((-b + D) / (2.0 * a));
	toRet.push_back((-b - D) / (2.0 * a));
	return toRet;
}
//Point
class Point
{
public:
	bool operator<(const Point &rhs)const;
	bool operator==(const Point &rhs)const;
	double x, y;
};

bool Point::operator<(const Point &rhs)const
{
	if(!equal(x, rhs.x))
		return x < rhs.x;
	return y < rhs.y;
}

bool Point::operator==(const Point &rhs)const
{
	return equal(x, rhs.x) && equal(y, rhs.y);
}


class less_convex_hull
{
	public:
	bool operator()(const Point &lhs, const Point &rhs)
	{
		if(!equal(lhs.y, rhs.y))
			return lhs.y < rhs.y;
		return lhs.x < rhs.x;
	}
};
class less_convex_hull2
{
	public:
	bool operator()(const pair<double, Point> &lhs, const pair<double, Point> &rhs)
	{
		if(lhs.first != rhs.first)
			return lhs.first < rhs.first;
		if(!equal(lhs.second.y, rhs.second.y))
			return lhs.second.y < rhs.second.y;
		return lhs.second.x < rhs.second.x;
	}
};
//Line
class Line
{
public:
	Line():a(), b(), c(){}
	Line(const Point &a, const Point &b);
	void create(const Point &a, const Point &b);
	double a, b, c;
};

Line::Line(const Point &p1, const Point &p2)
{
	create(p1, p2);
}
void Line::create(const Point &p1, const Point &p2)
{
	if(equal(p1.x, p2.x) && equal(p1.y, p2.y))
		throw "lo6o!!";
	if(equal(p1.y, p2.y))
	{
		a = 0.0;
		b = 1.0;
		c = -p1.y;
	}
	else
	{
		if(equal(p1.x, p2.x))
		{
			a = 1.0;
			b = 0.0;
			c = -p1.x;
		}	
		else
		{
			a = (p2.y - p1.y) / (p1.x - p2.x);
			b = 1.0;
			c = -a * p1.x - p1.y;
		}
	}
}
bool parallel(const Line &a, const Line& b)
{
	return ((isnula(a.a) && isnula(b.a)) || (isnula(a.b) && isnula(b.b)) || isnula((a.a / a.b) - (b.a / b.b)));
}

bool intersect(const Line &a, const Line& b, Point& result)
{
	if(parallel(a, b))
		return false;
	result.x = (b.b * a.c - a.b * b.c) / (b.a * a.b - a.a * b.b);
	if(!isnula(a.b))
		result.y = (-a.c - a.a * result.x) / a.b;
	else
		result.y = (-b.c - b.a * result.x) / b.b;
	return true;
}

bool liesOn(const Point &p1, const Line& l)
{
	return isnula(l.a * p1.x + l.b * p1.y + l.c);
}


//Segment
class Segment : public Line
{
public:
	Segment():beg(), end(){};
	Segment(const Point &a, const Point &b);
	void create(const Point &a, const Point &b);
	double length()const;
public:
	Point beg, end;
};

Segment::Segment(const Point &a, const Point &b)
{
	create(a, b);
}
void Segment::create(const Point &a, const Point &b)
{
	Line::create(a, b);
	beg = a;
	end = b;
}
double sideLength(const Point& p1, const Point &p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double Segment::length()const
{
	return sideLength(beg, end);
}

bool liesOn(const Point& p1, const Segment &s)
{
	return liesOn(p1, (Line)s) && ((p1.x - s.beg.x) * (p1.x - s.end.x) < epsilon && (p1.y - s.beg.y) * (p1.y - s.end.y) < epsilon);
}

bool intersect(const Segment &a, const Segment& b, Point &result)
{
	Point temp;
	if(!intersect((Line)a, (Line)b, temp))
		return false;
	if(liesOn(temp, a) && liesOn(temp, b))
	{
		result = temp;
		return true;
	}
	return false;
}

bool intersect(const Segment &a, const Line& b, Point &result)
{
	Point temp;
	if(!intersect((Line)a, b, temp))
		return false;
	if(liesOn(temp, a))
	{
		result = temp;
		return true;
	}
	return false;
}

Point divideSegment(const Point &beg, const Point &end, double begPart, double endPart)
{
	if(isnula(begPart))
		return beg;
	if(isnula(endPart))
		return end;
	Point toRet;
	toRet.x = (beg.x * endPart + end.x * begPart) / (begPart + endPart);
	toRet.y = (beg.y * endPart + end.y * begPart) / (begPart + endPart);
	return toRet;
}


Point outerDivideSegment(const Point &beg, const Point &end, double begPart, double endPart)
{
	if(isnula(begPart))
		return beg;
	if(isnula(endPart))
		return end;
	Point toRet;
	if(begPart > endPart)
	{
		toRet.x = (end.x * begPart - beg.x * endPart) / (begPart - endPart);
		toRet.y = (end.y * begPart - beg.y * endPart) / (begPart - endPart);
	}
	else
	{
		toRet.x = (beg.x * endPart - end.x * begPart) / (endPart - begPart);
		toRet.y = (beg.y * endPart - end.y * begPart) / (endPart - begPart);
	}
	return toRet;
}


//Oriented Areas
double triArea(const Point &p1, const Point &p2, const Point &p3)
{
	return (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x) / 2.0;
}

double poliArea(const vector<Point> &poligon)
{
	double res = 0.0;
	if(poligon.size() <= 2)
		return res;
	Point nula;
	nula.x = 0.0;
	nula.y = 0.0;
	for(int i = 1; i < (int)poligon.size(); i++)
	{
		res += triArea(poligon[i - 1], poligon[i], nula);
	}
	res += triArea(poligon.back(), poligon[0], nula);
	return res;
}


//Circle
class Circle
{
public:
	Circle(double d, const Point &c):r(d), center(c){};
	Circle(const Point &p1, const Point &p2, const Point &p3); 
	double r;
	Point center;
};
vector<Point> intersect(const Circle &c1, const Circle &c2)
{
	double centrala = sideLength(c1.center, c2.center);
	vector<Point> toRet;
	if(equal(centrala, c1.r + c2.r))
	{
		toRet.push_back(divideSegment(c1.center, c2.center, c1.r, c2.r));
		return toRet;
	}
	if(equal(centrala, max(c1.r, c2.r) - min(c1.r, c2.r)))
	{
		toRet.push_back(outerDivideSegment(c1.center, c2.center, c1.r, c2.r));
		return toRet;
	}
	if(centrala > c1.r + c2.r || centrala < max(c1.r, c2.r) - min(c1.r, c2.r))
		return toRet;
	double cosa = (c1.r * c1.r + centrala * centrala - c2.r * c2.r) / (2.0 * c1.r * centrala);
	double cosb = (c2.r * c2.r + centrala * centrala - c1.r * c1.r) / (2.0 * c2.r * centrala);
	Point temp;
	if(cosa > 0 && cosb > 0)
		temp = divideSegment(c1.center, c2.center, c1.r * cosa, c2.r * cosb);
	else
		temp = outerDivideSegment(c1.center, c2.center, c1.r * fabs(cosa), c2.r * fabs(cosb));
	Point p, nula;
	p.x = temp.y - c2.center.y;
	p.y = c2.center.x - temp.x;
	nula.x = 0.0;
	nula.y = 0.0;
	double len = sideLength(nula, p);
	double desiredLength = sqrt(1.0 - cosa * cosa) * c1.r;
	p.x *= desiredLength / len;
	p.y *= desiredLength / len;
	temp.x += p.x;
	temp.y += p.y;
	toRet.push_back(temp);
	temp.x -= 2.0 * p.x;
	temp.y -= 2.0 * p.y;
	toRet.push_back(temp);
	return toRet;

}
vector<Point> intersect(const Circle &c, const Line &l)
{
	vector<Point> toRet;
	if(!isnula(l.a))
	{
		Equation e(
			(1.0 + l.b * l.b / (l.a * l.a)),
			-2.0 * (c.center.y - l.b * l.c / (l.a * l.a) - c.center.x * l.b / l.a),
			c.center.y * c.center.y - c.r * c.r + l.c * l.c /(l.a * l.a) + 2.0 * c.center.x * l.c / l.a + c.center.x * c.center.x);
		vector<double> s(e.solutions());
		for(int i = 0; i < s.size(); i++)
		{
			Point p;
			p.y = s[i];
			p.x = (-l.b * p.y - l.c) / l.a;
			toRet.push_back(p);
		}
	}
	else
	{
		Equation e(
			(1.0 + l.a * l.a / (l.b * l.b)),
			-2.0 * (c.center.x - l.a * l.c / (l.b * l.b) - c.center.y * l.a / l.b),
			c.center.x * c.center.x - c.r * c.r + l.c * l.c /(l.b * l.b) + 2.0 * c.center.y * l.c / l.b + c.center.y * c.center.y);
		vector<double> s(e.solutions());
		for(int i = 0; i < s.size(); i++)
		{
			Point p;
			p.x = s[i];
			p.y = (-l.a * p.x - l.c) / l.b;
			toRet.push_back(p);
		}
	}
	return toRet;
}
Circle::Circle(const Point &p1, const Point &p2, const Point &p3)
{
	double a = sideLength(p2, p3), b = sideLength(p1, p3), c = sideLength(p1, p2);
	double cosa = cosinusa(b, c, a);
	double sina = sqrt(1.0 - cosa * cosa);
	r = (sina * a) / 2.0;
	Circle temp1(r, p1), temp2(r, p2);
	vector<Point> v = intersect(temp1, temp2);
	double area1 = triArea(p1, p2, p3), area2 = triArea(p1, p2, v[0]);
	if((area1 * area2 > -epsilon && cosa > 0) || (area1 * area2 < -epsilon && cosa < 0))
		center = v[0];
	else
		center = v[1];
}
bool isInside(const Point& p, const Circle &c)
{
	return (sideLength(p, c.center) - c.r) < epsilon;
}
vector<Point> tangentPoints(const Point &p, const Circle &c)
{
	double seku6ta = sideLength(p, c.center);
	vector<Point> toRet;
	if(seku6ta < c.r - epsilon)
		return toRet;
	if(seku6ta < c.r + epsilon)
	{
		toRet.push_back(p);
		return toRet;
	}
	Circle tempCircle(seku6ta, p);
	return intersect(c, tempCircle);
}
//Plygons
bool isInside(const Point &p, const vector<Point> &poligon)
{
	if(poligon.size() > 2)
	{
		double area = triArea(poligon.back(), poligon[0], p);
		if(isnula(area))
		{
			Segment s(poligon.back(), poligon[0]);
			return liesOn(p, s);
		}
		for(int i = 1; i < (int)poligon.size(); i++)
		{
			if(area * triArea(poligon[i - 1], poligon[i], p) < -epsilon)
				return false;
		}
		return true;
	}
	return false;
}
bool isInsideConcave(const Point &p, const vector<Point> &poligon)
{
	if(poligon.size() > 2)
	{
		double res = 0;
		for(int i = 1; i < (int)poligon.size(); i++)
		{
			double a = sideLength(poligon[i - 1], poligon[i]);
			double b = sideLength(p, poligon[i]);
			double c = sideLength(poligon[i - 1], p);
			double cos1 = (c * c + b * b - a * a) / (2.0 * b * c);
			res += acos(cos1);
		}
		double a = sideLength(poligon.back(), poligon[0]);
		double b = sideLength(p, poligon[0]);
		double c = sideLength(poligon.back(), p);
		double cos1 = (c * c + b * b - a * a) / (2.0 * b * c);
		res += acos(cos1);
		return !isnula(res);
	}
	return false;
}

vector<Point> convexHull(const vector<Point> &pointSet)
{
	if(pointSet.size() <= 2)
		return pointSet;
	Point minm = pointSet[0];
	for(int i = 1; i < pointSet.size(); i++)
		minm = min(minm, pointSet[i], less_convex_hull());

	vector<pair<double, Point> > tempPointSet;

	Point tempPoint;
	tempPoint.x = minm.x + 1.0;
	tempPoint.y = minm.y;
	double tempSide = sideLength(tempPoint, minm);

	for(int i = 0; i < pointSet.size(); i++)
	{
		if(equal(pointSet[i].y, minm.y))
		{
			if(equal(pointSet[i].x, minm.x))
				continue;
			tempPointSet.push_back(make_pair(1.0, pointSet[i]));
		}
		else
		{
			double a = sideLength(minm, pointSet[i]);
			double b = sideLength(tempPoint, pointSet[i]);
			double cos1 = (a * a + tempSide * tempSide - b * b) / (2.0 * a * tempSide);
			tempPointSet.push_back(make_pair(cos1, pointSet[i]));
		}
	}

	sort(tempPointSet.begin(), tempPointSet.end(), less_convex_hull2());
	tempPointSet.push_back(make_pair(0.0, minm));
	vector<Point> result;
	int stackSize = 2;
	result.push_back(minm);
	if(tempPointSet.size() == 0)
		return result;
	result.push_back(tempPointSet[0].second);
	int idx = 1;
	double tempD, tempD2;
	bool b;
	while(idx != tempPointSet.size())
	{
		b = true;
		if(result[stackSize - 1] == tempPointSet[idx].second)
		{
			idx++;
			continue;
		}
		while(stackSize >= 2 && (tempD = triArea(result[stackSize - 2], result[stackSize - 1], tempPointSet[idx].second)) > -epsilon)
		{
			if(tempD > epsilon)
			{
				result.pop_back();
				stackSize--;
			}
			else
			{
				if(stackSize == 2)
				{
					b = false;
					break;
				}
				else
				{
					tempD2 = triArea(result[stackSize - 3], result[stackSize - 2], tempPointSet[idx].second);
					if(tempD2 < tempD)
					{
						result.pop_back();
						stackSize--;
					}
					else
					{
						b = false;
						break;
					}
				}
			}
		}
		if(b)
		{
			result.push_back(tempPointSet[idx].second);
			stackSize++;
		}
		idx++;
	}
	result.pop_back();
	return result;
}


vector<Point> t1, t2;
Point corresponding(const Point& p)
{
	double c  = sideLength(t2[0], p), d = sideLength(t2[1], p);
	double coef = sideLength(t1[0], t1[1]) / sideLength(t2[0], t2[1]);
	Circle cir1(coef * c , t1[0]), cir2(coef * d, t1[1]);
	vector<Point> temp(intersect(cir1, cir2));
	if(temp.size() == 0)
	{
		Point p;
		p.x = 100000000;
		p.y = 100000000;
		return p;
	}
	if(isInside(temp[0], t1))
	{
		return temp[0];
	}
	if(temp.size() == 1)
	{
		Point p;
		p.x = 100000000;
		p.y = 100000000;
		return p;
	}
	return temp[1];
}
double res(const Point& p)
{
	if(!isInside(p, t2))
		return 1000000000;
	return sideLength(p, corresponding(p));
}
Point turnary()
{
	Point p;
	p.x = t2[0].x;
	p.y = t2[0].y;
	double step = 100000000.0;
	double maxm = res(p);
	while(step > epsilon2)
	{
		p.x -= step;
		double temp = res(p);
		if(temp - maxm > -epsilon || !isInside(p, t2))
		{
			p.x += 2 * step;
			temp = res(p);
			if(temp - maxm > -epsilon || !isInside(p, t2))
			{
				p.x -= step;
				p.y -= step;
				temp = res(p);
				if(temp - maxm > -epsilon || !isInside(p, t2))
				{
					p.y += 2 * step;
					temp = res(p);
					if(temp - maxm > -epsilon || !isInside(p, t2))
					{
						p.y -= step;
						step /= 2.0;
					}
					else
						maxm = temp;
				}
				else
					maxm = temp;
			}
			else
				maxm = temp;
		}
		else
			maxm = temp;
	}
	return p;
}
int main()
{
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	int numTests;
	t1.resize(3);
	t2.resize(3);
	cin >> numTests;
	for(int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d: ", testCounter + 1);
		cin >> t1[0].x >> t1[0].y >> t1[1].x >> t1[1].y >> t1[2].x >> t1[2].y;
		cin >> t2[0].x >> t2[0].y >> t2[1].x >> t2[1].y >> t2[2].x >> t2[2].y;
		Point p = turnary();
		printf("%.6lf %.6lf\n", p.x, p.y);
	}
	return 0;
}

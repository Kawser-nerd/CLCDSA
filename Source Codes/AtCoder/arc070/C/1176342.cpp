#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;    
 
static int64_t getMinCost(multiset<int64_t> &leftNodes,
		      multiset<int64_t> &rightNodes,
		      int64_t curmincost,
		      int64_t minpos,
		      int64_t loff,
		      int64_t roff)
{
    if (leftNodes.size() == 0) {
	return curmincost;
    }

    auto ilmax = leftNodes.end();
    ilmax--;
    int64_t lmax = *ilmax - loff;
    auto irmin = rightNodes.begin();
    int64_t rmin = *irmin + roff;
    
    if (lmax <= minpos) {
	if (minpos <= rmin) {
	    return curmincost;	    
	}
	return minpos - rmin + curmincost;
    } else {
	return lmax - minpos + curmincost;
    }
}
 
int main(void){
    int64_t n;
    int64_t mincost;
    multiset<int64_t> leftNodes;
    multiset<int64_t> rightNodes;
    stringstream st;
    string line;
      
    getline(cin, line);
    st.str(line);
    st >> n;
    
    int64_t nl, nr;
    int64_t l, r;
    int64_t loff, roff;
    loff = 0;
    roff = 0;    
    mincost = 0;    
    for (int64_t i = 0; i < n; i++) {
	getline(cin, line);
	st.str(line);
	st.clear();
	st.seekg(0);
	st >> nl >> nr;
	if (i >= 1) {
	    
	    mincost = getMinCost(leftNodes, rightNodes, mincost, l, loff, roff);

	    if (leftNodes.size() == 0) {
		leftNodes.insert(l);
		rightNodes.insert(l);
	    } else {
		auto ilmax = leftNodes.end();
		ilmax--;
		int64_t lmax = *ilmax - loff;
		if (lmax <= l) {
		    auto irmin = rightNodes.begin();
		    int64_t rmin = *irmin + roff;
		    if (l <= rmin) {
			leftNodes.insert(l + loff);
			rightNodes.insert(l - roff);
		    } else {
			rightNodes.insert(l - roff);
			rightNodes.insert(l - roff);

			leftNodes.insert(rmin + loff);
			rightNodes.erase(irmin);
		    }
		} else {
		    leftNodes.insert(l + loff);
		    leftNodes.insert(l + loff);

		    rightNodes.insert(lmax - roff);
		    leftNodes.erase(ilmax);
		}
	    }
	    roff += r - l;
	    loff += nr - nl;

#if 0
	    for (auto e : leftNodes) {
		cout << e - loff << " ";
	    }
	    for (auto e : rightNodes) {
		cout << e + roff << " ";
	    }	    
	    cout << endl;
#endif	
	}
	l = nl;
	r = nr;
    }
 
    mincost = getMinCost(leftNodes, rightNodes, mincost, l, loff, roff);
 
    cout << mincost << endl;
    return 0;
 
    
}
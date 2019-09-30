#include <iostream>
#include <vector>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ranked_index.hpp>

using namespace std;
using namespace boost::multi_index;
using Container = multi_index_container<
    int64_t,
    indexed_by<
        ranked_non_unique<identity<int64_t>>
    >
>;

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<int64_t> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int64_t> b(n + 1);
    for(int i = 0; i < n; i++) {
        b[i + 1] = b[i] + a[i] - k;   
    }
    
    Container c;
    int64_t ans = 0;
    
    for(int i = 0; i < n + 1; i++) {
        ans += c.upper_bound_rank(b[i]);
        c.insert(b[i]);
    }
    
    cout << ans << endl;
}
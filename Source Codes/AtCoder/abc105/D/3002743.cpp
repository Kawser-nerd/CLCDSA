#include <iostream>
#include <map>
#include <cstdint>

using namespace std;

uint64_t num_patterns(uint32_t c)
{
    if (c <= 1) {
        return 0;
    }

    uint64_t n = static_cast<uint64_t>(c) - 1;

    return (n + 1) * n / 2;
}

int main()
{
    uint32_t s = 0;
    uint32_t n;
    uint32_t m;
    map<uint32_t, uint32_t> counts;

    cin >> n >> m;

    counts[0] = 1;

    for (uint32_t i = 0; i < n; i++) {
        uint32_t a;
        cin >> a;

        s = (s + a) % m;
        counts[s]++;
    }

    uint64_t c = 0;
    typedef map<uint32_t, uint32_t>::iterator iterator;
    for (iterator it = counts.begin(); it != counts.end(); ++it) {
        c += num_patterns(it->second);
    }

    cout << c << endl;
}
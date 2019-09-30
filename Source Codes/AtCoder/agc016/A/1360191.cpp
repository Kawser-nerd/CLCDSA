#include <cstdio>
#include <cstdlib>
#include <map>
#include <cstring>

using namespace std;

std::map<char, int> last;
std::map<char, int> maxes;


int main()
{
    char buf[105];

    scanf("%s", buf);
    int n = strlen(buf);

    for(int i = 0; i < n; ++i)
    {
        int last_occ = -1;

        char c = buf[i];
        if(last.find(c) != last.end())
        {
            last_occ = last[c];
        }

        int odl = (i - last_occ) - 1;
        map<char, int>::iterator mi = maxes.find(c);
        if(mi == maxes.end())
        {
            maxes[c] = odl;
        }
        else
        {
            if(maxes[c] < odl)
                maxes[c] = odl;
        }

        last[c] = i;
    }

    for(map<char,int>::iterator it = last.begin(); it != last.end() ; ++it)
    {
        int odl = (n - it->second) - 1;
        char c = it->first;
        map<char, int>::iterator mi = maxes.find(c);
        if(mi == maxes.end())
        {
            maxes[c] = odl;
        }
        else
        {
            if(maxes[c] < odl)
                maxes[c] = odl;
        }
    }

    int mini = 1000;
    for(map<char,int>::iterator it = maxes.begin(); it != maxes.end(); ++it)
    {
        if(mini > it->second)
            mini = it->second;
    }

    printf("%d\n", mini);

    return 0;
}
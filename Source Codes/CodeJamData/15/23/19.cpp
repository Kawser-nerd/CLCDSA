#include <bits/stdc++.h>

using namespace std;


typedef long long LL;


const int NumDegrees = 360;


struct Fraction {
    LL num, denom;

    Fraction(){}
    Fraction(LL _num, LL _denom) : num(_num), denom(_denom) {}

    bool operator<(const Fraction& other) const {
        return (LL)num*other.denom < (LL)other.num*denom;
    }
};

struct Hiker {
    int degrees, speed;
    Hiker(){}
    Hiker(int deg, int v) : degrees(deg), speed(v) {}
};

struct DownUpSegment {
    Fraction timeStart, timeEnd;

    DownUpSegment(){}
    DownUpSegment(Fraction start, Fraction end) : timeStart(start), timeEnd(end) {}
    DownUpSegment(Hiker hiker){
        timeStart = Fraction((LL)(NumDegrees-hiker.degrees)*hiker.speed, 1);
        timeEnd   = Fraction((LL)(NumDegrees-hiker.degrees+NumDegrees)*hiker.speed, 1);
    }

    bool operator<(const DownUpSegment& other) const {
        return timeEnd < other.timeEnd;
    }
    bool operator>(const DownUpSegment& other) const {
        return other.timeEnd < timeEnd;
    }

    DownUpSegment advance() const {
        return DownUpSegment(timeEnd,
                Fraction(timeEnd.num+(timeEnd.num-timeStart.num), timeEnd.denom));
    }
};


struct Case {
    vector<Hiker> hikers;

    void input(){
        int N;
        scanf("%d", &N);

        for(int i = 0; i < N; i++){
            int D, H, M;
            scanf("%d%d%d", &D, &H, &M);
            for(int j = 0; j < H; j++){
                hikers.emplace_back(D, M+j);
            }
        }
    }


    void run(){
        int numHikers = (int)hikers.size();

        vector<Fraction> moveTimes;
        priority_queue<DownUpSegment, vector<DownUpSegment>,
                       greater<DownUpSegment>> segments;

        for(const Hiker& hiker: hikers){
            DownUpSegment stSegment(hiker);
            moveTimes.push_back(stSegment.timeStart);
            segments.push(stSegment);
//            printf("%lld/%lld\n", stSegment.timeStart.num, stSegment.timeStart.denom);
        }

        sort(moveTimes.begin(), moveTimes.end());
//        for(auto T: moveTimes) printf("%lld/%lld\n", T.num, T.denom);

        int result = numHikers;

        for(int segs = 0; segs < numHikers; segs++){
            DownUpSegment earliest = segments.top(); segments.pop();

//            printf("earliest ends at %d/%d\n", earliest.timeEnd.num,
//                    earliest.timeEnd.denom);

            int dst = distance(lower_bound(moveTimes.begin(),
                                           moveTimes.end(), earliest.timeEnd),
                               moveTimes.end());

//            printf("dst=%d segs=%d\n", dst, segs);


            result = min(result, segs+dst);
            segments.push(earliest.advance());
        }

        printf("%d\n", result);
    }
};

int main(){
    int numTests;
    scanf("%d", &numTests);

    for(int i = 1; i <= numTests; i++){
        Case C;
        C.input();
        printf("Case #%d: ", i);
        C.run();
    }
}

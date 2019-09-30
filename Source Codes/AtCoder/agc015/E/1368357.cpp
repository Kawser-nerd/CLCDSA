#include <algorithm>
#include <map>
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <fstream>


using namespace std;

#define present(c, e) ((c).find((e)) != (c).end())
#ifdef DEBUG
     #define debug(args...) {cerr << #args << ": "; dbg,args; cerr << endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif
struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr << v << " ";
        return *this;    
    }
} dbg;


const int N = 200000;
const int V = 1000000000;
const int MODULO = 1000000007;

struct Takahashi {
    int position;
    int velocity;
    int block_start;
    int block_end;
    bool seen;
};

Takahashi* t;

int n, x, v;
Takahashi takahashis[N];
int velocities[N];
int block_starts[N];
int block_ends[N];
unsigned long possibilities[N+1];

queue<int> block_starting_positions;
queue<int> block_ending_positions;
set<int> stops;
map<int, int>::iterator it;

bool compareByPosition(const Takahashi& x, const Takahashi& y) {
    return x.position < y.position;
}

bool compareByVelocity(int i, int j) {
    return takahashis[i].velocity < takahashis[j].velocity;
}

unsigned long long pow2mod(unsigned exponent, unsigned mod) {
    unsigned long long x = 1;
    unsigned long long y = 2;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}

int next_start, next_end;
int popNext(queue<int> *block_starting_positions, queue<int> *block_ending_positions) {
    if (block_starting_positions->empty()) {
        if (block_ending_positions->empty()) return -1;
        next_start = N + 1;  // or any large number
    } else {
        next_start = block_starting_positions->front();
    }
    next_end = block_ending_positions->front();
    if (next_start < next_end) {
        block_starting_positions->pop();
        return next_start;
    } else if (next_end < next_start) {
        block_ending_positions->pop();
        return next_end;
    } else {
        block_starting_positions->pop();
        block_ending_positions->pop();
        return next_start;
    }
}

int main() {
    // process input

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> v;
        takahashis[i] = {x, v, false};
        velocities[i] = i;
    }
    sort(takahashis, takahashis + n, compareByPosition);
    sort(velocities, velocities + n, compareByVelocity);

    // turn input into blocks

    int velocity_cursor = -1;
    int rightmost_smaller_velocity_index = 0;
    int block_end, upcoming_smaller_velocity_index;
    bool first;

    for (int i = 0; i < n; i++)
    {
        t = &takahashis[i];

        if (t->seen) continue;

        first = true;
        while (velocity_cursor < n - 1
               && t->velocity >= takahashis[velocities[velocity_cursor + 1]].velocity) {
            upcoming_smaller_velocity_index = velocities[++velocity_cursor];
            takahashis[velocities[velocity_cursor]].seen = true;
            rightmost_smaller_velocity_index = max(
                rightmost_smaller_velocity_index, upcoming_smaller_velocity_index);
            if (first) {
                block_end = rightmost_smaller_velocity_index;
                first = false;
            }
        }
        t->block_start = i;
        t->block_end = block_end;

        // Remove starts of previous blocks ending at same position
        if (block_ends[block_end]) {
            block_starts[takahashis[block_ends[block_end] - 1].block_start] = 0;
        }
        block_starts[i] = i + 1;
        block_ends[block_end] = i + 1;

        // iterator for later (ignore the ones removed for now)
        block_starting_positions.push(i);
        block_ending_positions.push(block_end);
    }
    // compute possibilities
    int val;
    long long int result;
    int block_start, current_block_end;
    bool all_blocks_move_to_left, has_new_block, has_block_end;
    queue<int> active_blocks;
    possibilities[0] = 1;

    long long int alpha = 0;
    int delta, k, next_stop;
    for (int i = 0; i < n; ++i) {
        debug("SSSSSSSSSSSSSSSS-----", i);
        // check for fast-track abilities
        next_stop = popNext(&block_starting_positions, &block_ending_positions);
        delta = next_stop - i;
        debug(next_stop, delta);
        if (delta > 0) {
            // fasttrack for delta rounds where no block starts or ends.
            result = (pow2mod(delta, MODULO) * possibilities[i]) % MODULO;
            result += ((pow2mod(delta, MODULO) - 1) * alpha) % MODULO;
            possibilities[i + delta] = result % MODULO;
            // skip to where there is a stop
            i += delta;
        }

        debug("-----");
        debug(i);
        // update active blocks
        has_new_block = block_starts[i];
        if (has_new_block) {
            active_blocks.push(i);
            alpha += possibilities[i];
            has_new_block = true;
            debug("ADD", i);
        }

        debug(active_blocks.size());

        // update possibilities
        result = alpha + (!has_new_block ? 2*possibilities[i] : 0);
        possibilities[i + 1] = result % MODULO;
        debug(i + 1, possibilities[i + 1]);

        has_block_end = block_ends[i];
        if (has_block_end) {
            val = active_blocks.front();
            alpha -= possibilities[takahashis[val].block_start];
            active_blocks.pop();
            debug("REMOVE", val);
        }
    }

    cout << possibilities[n] << endl;

    return 0;

};
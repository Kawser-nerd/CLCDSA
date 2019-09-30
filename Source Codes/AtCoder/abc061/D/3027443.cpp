#include <algorithm>
    #include <vector>
    #include <unordered_map>
    #include <functional>
    #include <climits>
    #include <iostream>
     
    class edge {
    public:
        edge(int to, long long cost);
        int get_to() const;
        long long get_cost() const;
    private:
        int to;
        long long cost;
    };
     
    edge::edge(int to, long long cost) : to(to), cost(cost) {}
     
    int edge::get_to() const { return to; }
     
    long long edge::get_cost() const { return cost; }
     
    class bellman_ford {
    private:
        //unordered_map????????????
        //first:????second:?????????
        std::unordered_map<int, std::vector<edge>> adj_list;
        int node_num;
        int start_point;
        std::vector<int> pred;//??????????
        std::vector<long long> costs;//?????
        bool is_negative_graph;//?????????????????
        std::vector<bool> is_negative_pass;//????????????????
     
    public:
        bellman_ford(const int node_num, const std::unordered_map<int, std::vector<edge>>& adj_list);
        void calc_min_cost(int start);
        long long get_cost(int end) const;
        bool get_is_negative_graph() const;
        std::vector<int> get_min_path(int end) const;
    };
     
    bellman_ford::bellman_ford(const int node_num, 
                                const std::unordered_map<int, std::vector<edge>>& adj_list) :
        adj_list(adj_list),
        start_point(0),
        node_num(node_num),
        pred(node_num + 1, INT_MAX),
        costs(node_num + 1, LLONG_MAX),
        is_negative_graph(false),
        is_negative_pass(node_num + 1, false)
    {}
     
    void bellman_ford::calc_min_cost(int start) {
        this->start_point = start;
        this->pred = std::vector<int>(node_num + 1, INT_MAX);
        this->costs = std::vector<long long>(node_num + 1, LLONG_MAX);
        this->is_negative_pass = std::vector<bool>(node_num + 1, false);
     
        pred[start] = -1;
        costs[start] = 0;
        for (int i = 0; i < 2 * node_num; i++) {
            for (auto &node : adj_list) {
                if (costs[node.first] == LLONG_MAX) continue;
                for (auto &adj : adj_list[node.first]) {
                    int adj_node = adj.get_to();
                    long long adj_cost = adj.get_cost() + costs[node.first];
                    if (adj_cost < costs[adj_node]) {
                        costs[adj_node] = adj_cost;
                        pred[adj_node] = node.first;
                        if (i >= node_num - 1) {
                            is_negative_pass[adj_node] = true;
                            is_negative_graph = true;
                        }
                    }
                   if(is_negative_pass[node.first] == true){
                       is_negative_pass[adj_node] = true;
                  }
                }
            }
        }
    }
     
    bool bellman_ford::get_is_negative_graph() const{
        return is_negative_graph;
    }
     
    long long bellman_ford::get_cost(int end) const {
        if (is_negative_pass[end] == false)
            return costs[end];
        else
            return LLONG_MIN;
    }
     
    std::vector<int> bellman_ford::get_min_path(int end) const {
        int node = end;
        std::vector<int> vec;
        vec.push_back(node);
        while (1) {
            if (is_negative_pass[node] == true ||
                pred[node] >= INT_MAX || pred[node] == -1) break;
            node = pred[node];
            vec.push_back(node);
        }
        std::reverse(vec.begin(), vec.end());
        return vec;
    }
     
    int main()
    {
        std::unordered_map<int, std::vector<edge>> adj_list;
        int node_num, edge_num, r;
        std::cin >> node_num;
        std::cin >> edge_num;
        //std::cin >> r;
        for (int i = 0; i < edge_num; i++) {
            int s, t;
            long long d;
            std::cin >> s;
            std::cin >> t;
            std::cin >> d;
            adj_list[s].push_back(edge(t, -d));
        }
     
        bellman_ford bell(node_num, adj_list);
        bell.calc_min_cost(1);
        long long cost = bell.get_cost(node_num);
        if (cost == LLONG_MIN) {
            std::cout << "inf\n";
        }
        else {
            std::cout << -cost << "\n";
        }
     
    }
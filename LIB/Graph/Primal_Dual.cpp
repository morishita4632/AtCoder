#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

/*
  最小費用流
  O(FE logV)

  初期化
  Primal_Dual<int, int> g(V);

  辺の追加
  g.add_edge(from, to, cap, cost);

  最大流
  g.min_cost_flow(s, t, F) << endl;
*/

template <typename flow_t, typename cost_t>
struct Primal_Dual {
  const cost_t INF_t;

  struct edge {
    int to;
    flow_t cap;
    cost_t cost;
    int rev;
    bool isrev;
  };
  vector<vector<edge> > graph;
  vector<cost_t> potential, min_cost;
  vector<int> prevv, preve;

  Primal_Dual(int V) : graph(V), INF_t(numeric_limits<cost_t>::max()) {}

  void add_edge(int from, int to, flow_t cap, cost_t cost) {
    graph[from].emplace_back(
        (edge){to, cap, cost, (int)graph[to].size(), false});
    graph[to].emplace_back(
        (edge){from, 0, -cost, (int)graph[from].size() - 1, true});
  }

  cost_t min_cost_flow(int s, int t, flow_t f) {
    int V = (int)graph.size();
    cost_t ret = 0;
    using Pi = pair<cost_t, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi> > que;
    potential.assign(V, 0);
    preve.assign(V, -1);
    prevv.assign(V, -1);

    while (f > 0) {
      min_cost.assign(V, INF_t);
      que.emplace(0, s);
      min_cost[s] = 0;
      while (!que.empty()) {
        Pi p = que.top();
        que.pop();
        if (min_cost[p.second] < p.first)
          continue;
        for (int i = 0; i < graph[p.second].size(); i++) {
          edge& e = graph[p.second][i];
          cost_t nextCost = min_cost[p.second] + e.cost + potential[p.second] -
                            potential[e.to];
          if (e.cap > 0 && min_cost[e.to] > nextCost) {
            min_cost[e.to] = nextCost;
            prevv[e.to] = p.second, preve[e.to] = i;
            que.emplace(min_cost[e.to], e.to);
          }
        }
      }
      if (min_cost[t] == INF_t)
        return -1;
      for (int v = 0; v < V; v++)
        potential[v] += min_cost[v];
      flow_t addflow = f;
      for (int v = t; v != s; v = prevv[v]) {
        addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
      }
      f -= addflow;
      ret += addflow * potential[t];
      for (int v = t; v != s; v = prevv[v]) {
        edge& e = graph[prevv[v]][preve[v]];
        e.cap -= addflow;
        graph[v][e.rev].cap += addflow;
      }
    }
    return ret;
  }

  void output() {
    for (int i = 0; i < graph.size(); i++) {
      for (auto& e : graph[i]) {
        if (e.isrev)
          continue;
        auto& rev_e = graph[e.to][e.rev];
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/"
             << rev_e.cap + e.cap << ")" << endl;
      }
    }
  }
};

/*
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=jp
*/

int main() {
  int V, E, F;
  cin >> V >> E >> F;
  vector<int> u(E), v(E), c(E), d(E);
  rep(i, E) cin >> u[i] >> v[i] >> c[i] >> d[i];

  Primal_Dual<int, int> g(V);
  rep(i, E) {
    g.add_edge(u[i], v[i], c[i], d[i]);
  }
  cout << g.min_cost_flow(0, V - 1, F) << endl;
}
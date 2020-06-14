#include <iostream>
#include <memory>
#include <queue>
#include <map>
#include <vector>

#include "angle_finder.h"


const float COST_FUDGE = 3.0;


class Graph {
    struct Edge {
        angle from;
        movement via;
        float cost;
    };
    struct Node {
        std::multimap<angle, Edge> edges;


        float best;
    };

    Node nodes[0xFFFF + 1];
    //std::uint16_t seen;


    void add_edge(Edge e, Node& n) {
        n.edges.insert(e.from, e);

        n.edges.push_back(e);
        n.best = (n.best < e.cost) ? n.best : e.cost;
    }

    bool maybe_add_edge(Edge e, Node& n) {
        if (n.edges.size() == 0) {
            this->add_edge(e, n);
            return true;
        }

        if (e.cost > n.best + COST_FUDGE) {
            return false;
        }

        for (auto&& old : n.edges) {
            //if (old.from == e.from)
        }

        return false;
    }

public:
    void initial(angle a, float cost) {
        this->nodes[a].edges.push_back({
            .from = NONE,
            .cost = cost,
        });

        this->nodes[a].best = cost;
    }

    void explore() {
    }

    int check() {
        return this->nodes->edges.size();
    }
};

int main()
{
    //std::optional<int> x = 0;

    auto g = std::make_unique<Graph>();

    std::cout << "Hello, world!\n";
    std::cout << g->check() << "\n";
    return 0;
}

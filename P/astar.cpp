#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
    vector<vector<string>> data;
    int level;
    int fval;

    Node(const vector<vector<string>> &data, int level, int fval) : data(data), level(level), fval(fval) {}

    pair<int, int> find(const vector<vector<string>> &puz, const string &x) {
        for (int i = 0; i < puz.size(); i++) {
            for (int j = 0; j < puz[i].size(); j++) {
                if (puz[i][j] == x) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }

    // Generate child nodes by moving the blank space
    vector<Node> generate_child() {
        vector<Node> children;
        auto [x, y] = find(data, "_");
        vector<vector<int>> val_list = {{x, y - 1}, {x, y + 1}, {x - 1, y}, {x + 1, y}};

        for (const auto &pos : val_list) {
            auto child_data = shuffle(data, x, y, pos[0], pos[1]);
            if (!child_data.empty()) {
                children.push_back(Node(child_data, level + 1, 0));
            }
        }

        return children;
    }

    // Shuffle the blank space in the given direction
    vector<vector<string>> shuffle(
        const vector<vector<string>> &puz,
        int x1,
        int y1,
        int x2,
        int y2) {
        if (x2 >= 0 && x2 < puz.size() && y2 >= 0 && y2 < puz[0].size()) {
            auto temp_puz = copy(puz);
            swap(temp_puz[x1][y1], temp_puz[x2][y2]);
            return temp_puz;
        } else {
            return {};
        }
    }

    vector<vector<string>> copy(const vector<vector<string>> &root) {
        vector<vector<string>> temp(root.size());
        for (size_t i = 0; i < root.size(); ++i) {
            temp[i] = root[i];
        }
        return temp;
    }
};

struct Puzzle {
    int size;
    vector<Node> open;
    vector<Node> closed;

    Puzzle(int size) : size(size) {}

    vector<vector<string>> accept() {
        vector<vector<string>> puz(size, vector<string>(size));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cin >> puz[i][j];
            }
        }
        return puz;
    }

    int f(const Node &start, const vector<vector<string>> &goal) {
        return h(start.data, goal) + start.level;
    }

    int h(const vector<vector<string>> &start, const vector<vector<string>> &goal) {
        int temp = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (start[i][j] != goal[i][j] && start[i][j] != "_") {
                    temp++;
                }
            }
        }
        return temp;
    }

    void process() {
        cout << "Enter the start state matrix:" << endl;
        auto start_data = accept();

        cout << "Enter the goal state matrix:" << endl;
        auto goal_data = accept();

        Node start(start_data, 0, 0);
        start.fval = f(start, goal_data);
        open.push_back(start);

        while (!open.empty()) {
            auto cur = open.front();
            cout << "Current state:\n";
            for (const auto &row : cur.data) {
                for (const auto &el : row) {
                    cout << el << " ";
                }
                cout << endl;
            }
            cout << endl;

            if (h(cur.data, goal_data) == 0) {
                cout << "Goal state reached!" << endl;
                break;
            }

            auto children = cur.generate_child();
            for (auto &child : children) {
                child.fval = f(child, goal_data);
                open.push_back(child);
            }

            closed.push_back(cur);
            open.erase(open.begin());

            sort(open.begin(), open.end(), [](const Node &a, const Node &b) {
                return a.fval < b.fval;
            });
        }
    }
};

int main() {
    Puzzle puz(3);
    puz.process();
    return 0;
}

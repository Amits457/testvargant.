
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Newspaper {
    string name;
    double price;
};

vector<vector<string>> find_combinations(vector<Newspaper>& newspapers, int budget, int index) {
    if (index == newspapers.size() || budget <= 0) {
        if (budget == 0) {
            return {{}};
        }
        return {};
    }
    auto not_include = find_combinations(newspapers, budget, index + 1);
    double price = newspapers[index].price;
    if (price <= budget) {
        auto include = find_combinations(newspapers, budget - price, index + 1);
        for (auto& comb : include) {
            comb.push_back(newspapers[index].name);
        }
        for (auto& comb : include) {
            not_include.push_back(comb);
        }
    }
    return not_include;
}

int main() {
    vector<Newspaper> newspapers = {{"TOI", 3}, {"Hindu", 2.5}, {"ET", 4}, {"BM", 1.5}, {"HT", 2}};
    int budget = 40;
    auto res = find_combinations(newspapers, budget, 0);
    for (const auto& c : res) {
        for (const auto& s : c) {
            cout << s << " "<<endl;
        }

    }
    return 0;
}

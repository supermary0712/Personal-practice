#include <iostream>
#include <array>

using namespace std;

int main()
{
    int size = 4;

    std::array<int, 4> values{};

    for (int i = 0; i < values.size(); i++)
    {
        values.at(i) = i;
    }

    cout << get<3>(values) << endl;

    if (!values.empty()) {
        for (auto val = values.begin(); val < values.end(); val++)
        {
            cout << *val << " ";
        }
    }

    return 0;
}
#include "std_lib_facilities.h"
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <fstream>
#include <list>
#include <algorithm>

struct Item {

    string name;
    int iid;
    float value;
};
ifstream& operator >> (ifstream& is, Item& out) {

    is >> out.name;
    is >> out.iid;
    is >> out.value;
    return is;
}
ostream& operator << (ostream& os, const Item& i) {

    os << i.name << ' ' << i.iid << ' ' << i.value;
    return os;
}
bool CompareStrings(const string& s0, const string& s1) {

    for (int i = 0; i< s0.length(); ++i) {
        if (i == s1.length()) return false;
        char xx = tolower(s0[i]);
        char yy = tolower(s1[i]);
        if (xx < yy) return true;
        if (yy < xx) return false;
    }
    if (s0.length()== s1.length()) return false;
    return true;
}

template<typename T0, typename T1>
void read_into_map_from_cin(map<T0, T1>& map) {

    T0 i0;
    T1 i1;
    for(; cin >> i0 >> i1;) {
        map[i0] = i1;
    }
}
template<typename T0, typename T1>
void print_map(map<T0,T1>& map) {
    for(auto& i : map) {
        cout << i.first << ' ' << i.second << endl;
    }
}
template<typename T>
void print_vector(const vector<T>& vec) {
    for(auto& i : vec) {
        cout << i << endl;
    }
}

int main() {
    
    vector<Item> vi;
    ifstream file("items");
    for(Item i; file >> i; vi.push_back(i));

    sort(vi.begin(), vi.end(),
        [](const Item& i0, const Item& i1) {
            return CompareStrings(i0.name, i1.name);
        });
    sort(vi.begin(), vi.end(),
        [](const Item& i0, const Item& i1) {
            return i0.iid < i1.iid;
        });
    sort(vi.begin(), vi.end(),
        [](const Item& i0, const Item& i1) {
            return i0.value < i1.value;
        });

    cout << "vi contents" << endl;
    for(auto it = vi.rbegin(); it != vi.rend(); it++) {
        cout << *it << endl;
    }

    vi.insert(vi.begin(), {"horse shoe", 99, 12.34});
    vi.insert(vi.begin(), {"Cannon S400", 9988, 499.95});

    vi.erase(find_if(vi.begin(), vi.end(), 
        [](const Item& i){ return i.name == "horse shoe";}));
    vi.erase(find_if(vi.begin(), vi.end(), 
        [](const Item& i){ return i.iid == 0;}));

    list<Item> li;
    file.seekg(ios::beg);
    for(Item i; file >> i; li.push_back(i));

    cout << "li contents" << endl;
    for(auto it = li.rbegin(); it != li.rend(); it++) {
        cout << *it << endl;
    }

    li.insert(li.begin(), {"horse shoe", 99, 12.34});
    li.insert(li.begin(), {"Cannon S400", 9988, 499.95});

    map<string, int> msi;
    for(auto& i : vi) {
        msi[i.name] = i.iid;
    }

    cout << "msi contents" << endl;
    print_map(msi);

    msi.clear();
    read_into_map_from_cin(msi);
    int sum = 0;
    for(auto& i : msi) {
        cout << i.first << ' ' << i.second << endl;
        sum += i.second;
    }

    cout << "Sum: " << sum << endl;
    map<int, string> mis;
    for(auto& i : msi) {
        mis[i.second] = i.first;
    }

    vector<float> vd;
    ifstream floatFile("floats");
    for(float i; file >> i; vd.push_back(i));
    print_vector(vd);

    cout << "(vd[i] vi2[i])" << endl;
    vector<int> vi2;
    float vdSum = 0;
    int vi2Sum = 0;
    for(auto& i : vd) {
        vi2.push_back(i);
        cout << i << ' ' << vi2.back() << endl;
        vdSum += i;
        vi2Sum += vi2.back();
    }
    cout << "vd sum: " << vdSum << " vi2 sum: " << vi2Sum << " diff: " << vdSum - (float)vi2Sum << endl;

    cout << "vd reversed" << endl;
    reverse(vd.begin(), vd.end());
    print_vector(vd);

    auto mean = vdSum / vd.size();
    cout << "vd mean: " << mean << endl;

    vector<float> vd2;
    for(auto& i : vd) {
        if(i < mean) {
            vd2.push_back(i);
        }
    }
    sort(vd2.begin(), vd2.end());

    cout << "vd2 contents" << endl;
    print_vector(vd2);
}



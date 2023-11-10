#include <iostream>
#include <stack>
#include <string>
using namespace std;

string MaHoaChuoi(const string& s) {
    stack<char> nganXep;

    for (char c : s) {
        if (islower(c)) {
            char maHoa = 'z' - (c - 'a');
            nganXep.push(maHoa);
        }
    }

    string chuoiMaHoa;

    while (!nganXep.empty()) {
        chuoiMaHoa += nganXep.top();
        nganXep.pop();
    }

    return chuoiMaHoa;
}

int main() {
    string chuoi;
    cout << "Nhap chuoi: ";
    getline(cin, chuoi);

    string chuoiMaHoa = MaHoaChuoi(chuoi);

    cout << "Chuoi ma hoa: " << chuoiMaHoa << endl;

    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

bool KiemTraNguyenTo(int n) {
    if (n < 2) {
        return false;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

void InDaySoSieuNguyenTo(int n) {
    queue<int> hangDoi;

    for (int i = 2; i <= n; i++) {
        if (KiemTraNguyenTo(i)) {
            hangDoi.push(i);
        }
    }

    while (!hangDoi.empty()) {
        cout << hangDoi.front() << " ";
        hangDoi.pop();
    }

    cout << endl;
}

int main() {
    int n;
    cout << "Nhap so n: ";
    cin >> n;

    InDaySoSieuNguyenTo(n);

    return 0;
}
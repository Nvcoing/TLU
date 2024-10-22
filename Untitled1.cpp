#include <iostream>
#include <string>
#include <limits>

class Nha {
private:
    std::string diaChi;
    int soPhongNgu;
    int soPhongTam;
    double dienTich;

public:
    // Constructor kh�ng tham s?
    Nha() : diaChi(""), soPhongNgu(0), soPhongTam(0), dienTich(0.0) {}

    // Getter v� Setter cho diaChi
    std::string getDiaChi() const {
        return diaChi;
    }

    void setDiaChi(const std::string& diaChi) {
        this->diaChi = diaChi;
    }

    // Getter v� Setter cho soPhongNgu
    int getSoPhongNgu() const {
        return soPhongNgu;
    }

    void setSoPhongNgu(int soPhongNgu) {
        this->soPhongNgu = soPhongNgu;
    }

    // Getter v� Setter cho soPhongTam
    int getSoPhongTam() const {
        return soPhongTam;
    }

    void setSoPhongTam(int soPhongTam) {
        this->soPhongTam = soPhongTam;
    }

    // Getter v� Setter cho dienTich
    double getDienTich() const {
        return dienTich;
    }

    void setDienTich(double dienTich) {
        this->dienTich = dienTich;
    }

    // Phuong th?c nh?p th�ng tin nh�
    void nhapThongTin() {
        std::cout << "Nhap dia chi: ";
        std::getline(std::cin, diaChi);

        std::cout << "Nhap so phong ngu: ";
        std::cin >> soPhongNgu;

        std::cout << "Nhap so phong tam: ";
        std::cin >> soPhongTam;

        std::cout << "Nhap dien tich: ";
        std::cin >> dienTich;

        // X�a k� t? newline c�n l?i trong buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Phuong th?c hi?n th? s? ph�ng t?m
    void hienThiSoPhongTam() const {
        std::cout << "So phong tam: " << soPhongTam << std::endl;
    }

    // N?p ch?ng to�n t? < cho s? ph�ng t?m (h�m th�nh vi�n)
    bool operator<(const Nha &other) const {
        return soPhongTam < other.soPhongTam;
    }

    // N?p ch?ng to�n t? > cho s? ph�ng t?m (h�m th�nh vi�n)
    bool operator>(const Nha &other) const {
        return soPhongTam > other.soPhongTam;
    }

    // Khai b�o c�c h�m b?n d? n?p ch?ng to�n t? + v� += cho s? ph�ng ng?
    friend Nha operator+(const Nha &nha1, const Nha &nha2);
    friend Nha& operator+=(Nha &nha1, const Nha &nha2);
};

// �?nh nghia h�m b?n d? n?p ch?ng to�n t? + cho s? ph�ng ng?
Nha operator+(const Nha &nha1, const Nha &nha2) {
    Nha result;
    result.diaChi = nha1.diaChi + " & " + nha2.diaChi; // G?p d?a ch? c?a hai nh� (tu? ch?n)
    result.soPhongNgu = nha1.soPhongNgu + nha2.soPhongNgu;
    result.soPhongTam = nha1.soPhongTam; // Kh�ng thay d?i s? ph�ng t?m
    result.dienTich = nha1.dienTich + nha2.dienTich; // G?p di?n t�ch c?a hai nh� (tu? ch?n)
    return result;
}

// �?nh nghia h�m b?n d? n?p ch?ng to�n t? += cho s? ph�ng ng?
Nha& operator+=(Nha &nha1, const Nha &nha2) {
    nha1.soPhongNgu += nha2.soPhongNgu;
    return nha1;
}

int main() {
    // T?o d?i tu?ng nh� v� nh?p th�ng tin
    Nha nha1, nha2;

    std::cout << "Nhap thong tin cho ngoi nha thu nhat:" << std::endl;
    nha1.nhapThongTin();

    std::cout << "Nhap thong tin cho ngoi nha thu hai:" << std::endl;
    nha2.nhapThongTin();

    // Hi?n th? s? ph�ng t?m c?a hai ng�i nh�
    std::cout << "So phong tam cua ngoi nha thu nhat: ";
    nha1.hienThiSoPhongTam();

    std::cout << "So phong tam cua ngoi nha thu hai: ";
    nha2.hienThiSoPhongTam();

    // So s�nh s? ph�ng t?m c?a hai ng�i nh�
    if (nha1 < nha2) {
        std::cout << "Nha thu nhat co it phong tam hon nha thu hai." << std::endl;
    } else if (nha1 > nha2) {
        std::cout << "Nha thu nhat co nhieu phong tam hon nha thu hai." << std::endl;
    } else {
        std::cout << "Hai ngoi nha co so phong tam bang nhau." << std::endl;
    }

    // C?ng s? ph�ng ng? c?a hai ng�i nh� v� hi?n th? k?t qu?
    Nha nha3 = nha1 + nha2;
    std::cout << "So phong ngu sau khi cong cua hai ngoi nha: " << nha3.getSoPhongNgu() << std::endl;

    // C?ng b?ng s? ph�ng ng? c?a hai ng�i nh� v� hi?n th? k?t qu?
    nha1 += nha2;
    std::cout << "So phong ngu cua ngoi nha thu nhat sau khi cong bang: " << nha1.getSoPhongNgu() << std::endl;

    return 0;
}

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
    // Constructor không tham s?
    Nha() : diaChi(""), soPhongNgu(0), soPhongTam(0), dienTich(0.0) {}

    // Getter và Setter cho diaChi
    std::string getDiaChi() const {
        return diaChi;
    }

    void setDiaChi(const std::string& diaChi) {
        this->diaChi = diaChi;
    }

    // Getter và Setter cho soPhongNgu
    int getSoPhongNgu() const {
        return soPhongNgu;
    }

    void setSoPhongNgu(int soPhongNgu) {
        this->soPhongNgu = soPhongNgu;
    }

    // Getter và Setter cho soPhongTam
    int getSoPhongTam() const {
        return soPhongTam;
    }

    void setSoPhongTam(int soPhongTam) {
        this->soPhongTam = soPhongTam;
    }

    // Getter và Setter cho dienTich
    double getDienTich() const {
        return dienTich;
    }

    void setDienTich(double dienTich) {
        this->dienTich = dienTich;
    }

    // Phuong th?c nh?p thông tin nhà
    void nhapThongTin() {
        std::cout << "Nhap dia chi: ";
        std::getline(std::cin, diaChi);

        std::cout << "Nhap so phong ngu: ";
        std::cin >> soPhongNgu;

        std::cout << "Nhap so phong tam: ";
        std::cin >> soPhongTam;

        std::cout << "Nhap dien tich: ";
        std::cin >> dienTich;

        // Xóa kí t? newline còn l?i trong buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Phuong th?c hi?n th? s? phòng t?m
    void hienThiSoPhongTam() const {
        std::cout << "So phong tam: " << soPhongTam << std::endl;
    }

    // N?p ch?ng toán t? < cho s? phòng t?m (hàm thành viên)
    bool operator<(const Nha &other) const {
        return soPhongTam < other.soPhongTam;
    }

    // N?p ch?ng toán t? > cho s? phòng t?m (hàm thành viên)
    bool operator>(const Nha &other) const {
        return soPhongTam > other.soPhongTam;
    }

    // Khai báo các hàm b?n d? n?p ch?ng toán t? + và += cho s? phòng ng?
    friend Nha operator+(const Nha &nha1, const Nha &nha2);
    friend Nha& operator+=(Nha &nha1, const Nha &nha2);
};

// Ð?nh nghia hàm b?n d? n?p ch?ng toán t? + cho s? phòng ng?
Nha operator+(const Nha &nha1, const Nha &nha2) {
    Nha result;
    result.diaChi = nha1.diaChi + " & " + nha2.diaChi; // G?p d?a ch? c?a hai nhà (tu? ch?n)
    result.soPhongNgu = nha1.soPhongNgu + nha2.soPhongNgu;
    result.soPhongTam = nha1.soPhongTam; // Không thay d?i s? phòng t?m
    result.dienTich = nha1.dienTich + nha2.dienTich; // G?p di?n tích c?a hai nhà (tu? ch?n)
    return result;
}

// Ð?nh nghia hàm b?n d? n?p ch?ng toán t? += cho s? phòng ng?
Nha& operator+=(Nha &nha1, const Nha &nha2) {
    nha1.soPhongNgu += nha2.soPhongNgu;
    return nha1;
}

int main() {
    // T?o d?i tu?ng nhà và nh?p thông tin
    Nha nha1, nha2;

    std::cout << "Nhap thong tin cho ngoi nha thu nhat:" << std::endl;
    nha1.nhapThongTin();

    std::cout << "Nhap thong tin cho ngoi nha thu hai:" << std::endl;
    nha2.nhapThongTin();

    // Hi?n th? s? phòng t?m c?a hai ngôi nhà
    std::cout << "So phong tam cua ngoi nha thu nhat: ";
    nha1.hienThiSoPhongTam();

    std::cout << "So phong tam cua ngoi nha thu hai: ";
    nha2.hienThiSoPhongTam();

    // So sánh s? phòng t?m c?a hai ngôi nhà
    if (nha1 < nha2) {
        std::cout << "Nha thu nhat co it phong tam hon nha thu hai." << std::endl;
    } else if (nha1 > nha2) {
        std::cout << "Nha thu nhat co nhieu phong tam hon nha thu hai." << std::endl;
    } else {
        std::cout << "Hai ngoi nha co so phong tam bang nhau." << std::endl;
    }

    // C?ng s? phòng ng? c?a hai ngôi nhà và hi?n th? k?t qu?
    Nha nha3 = nha1 + nha2;
    std::cout << "So phong ngu sau khi cong cua hai ngoi nha: " << nha3.getSoPhongNgu() << std::endl;

    // C?ng b?ng s? phòng ng? c?a hai ngôi nhà và hi?n th? k?t qu?
    nha1 += nha2;
    std::cout << "So phong ngu cua ngoi nha thu nhat sau khi cong bang: " << nha1.getSoPhongNgu() << std::endl;

    return 0;
}

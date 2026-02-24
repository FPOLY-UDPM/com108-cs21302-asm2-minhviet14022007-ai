/******************************************************************************
 * Họ và tên: [Trương Minh Việt]
 * MSSV:      [PS48885]
 * Lớp:       [COM108]
 *****************************************************************************/

// Tạo file asm2.c và hoàn thiện nội dung Assignment từ nội dung file asm1.c


// Danh sách các chức năng trong ASM1:
// 1. Chức năng số 1: Kiểm tra số nguyên
// 2. Chức năng số 2. Tìm Ước số chung và bội số chung của 2 số 
// 3. Chức năng số 3: Chương trình tính tiền cho quán Karaoke
// 4. Chức năng số 4: Tính tiền điện 
// 5. Chức năng số 5: Chức năng đổi tiền 
// 6. Chức năng số 6: Xây dựng chức năng tính lãi suất vay ngân hàng vay trả góp 
// 7. Chức năng số 7: Xây dựng chương trình vay tiền mua xe
// 8. Chức năng số 8: Sắp xếp thông tin sinh viên
// 9. Chức năng số 9: Xây dựng game FPOLY-LOTT
// 10. Chức năng số 10: Xây dựng chương trình tính toán phân số 
// Viết chương trình C thực hiện các chức năng trên

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
void chucNang1();
int isPrime(int n);
int isPerfectSquare(int n);
void chucNang2();
int getGCD(int a, int b);
void chucNang3();
void chucNang4();
void chucNang5();
void chucNang6();
void chucNang7();
struct SinhVien {
    char ten[50];
    float diem;
    char hocLuc[20];
};
void xepLoai(struct SinhVien *sv);
void chucNang8();
void chucNang9();
struct PhanSo {
    int tu;
    int mau;
};
void rutGon(struct PhanSo *ps);
void chucNang10();
int main() {
    int choice;
    do {
        printf("\n--- MENU ASSIGNMENT ---\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim UCLN va BCNN\n");
        printf("3. Tinh tien Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Doi tien\n");
        printf("6. Tinh lai vay ngan hang tra gop\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang (0-10): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: chucNang1(); break;
            case 2: chucNang2(); break;
            case 3: chucNang3(); break;
            case 4: chucNang4(); break;
            case 5: chucNang5(); break;
            case 6: chucNang6(); break;
            case 7: chucNang7(); break;
            case 8: chucNang8(); break;
            case 9: chucNang9(); break;
            case 10: chucNang10(); break;
            case 0: printf("Thoat chuong trinh.\n"); break;
            default: printf("Lua chon khong hop le.\n");
        }
    } while(choice != 0);
    return 0;
}
int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
int isPerfectSquare(int n) {
    if (n < 0) return 0;
    int root = sqrt(n);
    return (root * root == n);
}
void chucNang1() {
    float x;
    printf("Nhap x: ");
    scanf("%f", &x);
    if (x == (int)x) {
        printf("%.0f la so nguyen\n", x);
        int n = (int)x;
        if (isPrime(n)) printf("%d la so nguyen to\n", n);
        else printf("%d khong phai so nguyen to\n", n);

        if (isPerfectSquare(n)) printf("%d la so chinh phuong\n", n);
        else printf("%d khong phai so chinh phuong\n", n);
    } else {
        printf("%f khong phai la so nguyen\n", x);
    }
}
int getGCD(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (a == 0 || b == 0) return a + b;
    while (a != b) {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}
void chucNang2() {
    int x, y;
    printf("Nhap x, y: ");
    scanf("%d %d", &x, &y);
    int gcd = getGCD(x, y);
    int lcm = (abs(x * y)) / gcd;
    printf("UCLN: %d\n", gcd);
    printf("BCNN: %d\n", lcm);
}
void chucNang3() {
    int start, end;
    printf("Nhap gio bat dau, ket thuc: ");
    scanf("%d %d", &start, &end);
    if (start < 12 || end > 23 || start >= end) {
        printf("Gio khong hop le. Quan chi hoat dong tu 12h den 23h.\n");
        return;
    }
    int hours = end - start;
    float total = 0;
    if (hours <= 3) {
        total = hours * 150000;
    } else {
        total = 3 * 150000 + (hours - 3) * 150000 * 0.7;
    }
    if (start >= 14 && start <= 17) {
        total = total * 0.9;
    }
    printf("Tong tien can thanh toan: %.0f VNĐ\n", total);
}
void chucNang4() {
    float kwh, tien = 0;
    printf("Nhap kwh: ");
    scanf("%f", &kwh);
    if (kwh <= 50) tien = kwh * 1678;
    else if (kwh <= 100) tien = 50 * 1678 + (kwh - 50) * 1734;
    else if (kwh <= 200) tien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
    else if (kwh <= 300) tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 200) * 2536;
    else if (kwh <= 400) tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - 300) * 2834;
    else tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kwh - 400) * 2927;
    printf("So tien dien phai tra: %.0f VNĐ\n", tien);
}
void chucNang5() {
    int tien, tienGoc;
    printf("Nhap so tien can doi: ");
    scanf("%d", &tien);
    
    tienGoc = tien;
    int menhGia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int soTo;
    
    for (int i = 0; i < 9; i++) {
        if (menhGia[i] == tienGoc) {
            continue;
        }
        
        soTo = tien / menhGia[i];
        if (soTo > 0) {
            printf("%d to %d\n", soTo, menhGia[i]);
            tien = tien % menhGia[i];
        }
    }
}
void chucNang6() {
    float tienVay, lai, goc, tongTra;
    printf("Nhap so tien muon vay: ");
    scanf("%f", &tienVay);
    goc = tienVay / 12;
    printf("\nKy han\tLai phai tra\tGoc phai tra\tSo tien phai tra\tSo tien con lai\n");
    for (int i = 1; i <= 12; i++) {
        lai = tienVay * 0.05;
        tongTra = goc + lai;
        tienVay -= goc;
        if (tienVay < 0) tienVay = 0;
        printf("%d\t%.0f\t\t%.0f\t\t%.0f\t\t\t%.0f\n", i, lai, goc, tongTra, tienVay);
    }
}
void chucNang7() {
    float phanTramVay;
    printf("Nhap phan tram vay toi da (VD: 80): ");
    scanf("%f", &phanTramVay);
    float giaXe = 500000000;
    float tienVay = giaXe * (phanTramVay / 100);
    float traTruoc = giaXe - tienVay;
    printf("So tien tra lan dau: %.0f VNĐ\n", traTruoc);
    int thoiHanThang = 24 * 12;
    float laiSuatThang = 0.072 / 12;
    float gocHangThang = tienVay / thoiHanThang;
    printf("\nThang\tTien lai\tTien goc\tTien phai tra\tTien con lai\n");
    for (int i = 1; i <= thoiHanThang; i++) {
        float tienLai = tienVay * laiSuatThang;
        float tongTra = gocHangThang + tienLai;
        tienVay -= gocHangThang;
        if (tienVay < 0) tienVay = 0;
        if (i <= 24 || i == thoiHanThang) {
             printf("%d\t%.0f\t%.0f\t%.0f\t%.0f\n", i, tienLai, gocHangThang, tongTra, tienVay);
        }
        if (i == 24) {
            printf("... (Du lieu duoc rut gon tren man hinh) ...\n");
        }
    }
}
void xepLoai(struct SinhVien *sv) {
    if (sv->diem >= 9.0) strcpy(sv->hocLuc, "Xuat sac");
    else if (sv->diem >= 8.0) strcpy(sv->hocLuc, "Gioi");
    else if (sv->diem >= 6.5) strcpy(sv->hocLuc, "Kha");
    else if (sv->diem >= 5.0) strcpy(sv->hocLuc, "Trung binh");
    else strcpy(sv->hocLuc, "Yeu");
}
void chucNang8() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    struct SinhVien sv[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap ten SV thu %d: ", i + 1);
        scanf(" %[^\n]", sv[i].ten);
        printf("Nhap diem SV thu %d: ", i + 1);
        scanf("%f", &sv[i].diem);
        xepLoai(&sv[i]);
    }   
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sv[i].diem < sv[j].diem) {
                struct SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
    printf("\nDanh sach sinh vien sau khi sap xep (Diem giam dan):\n");
    for (int i = 0; i < n; i++) {
        printf("%s - Diem: %.1f - Hoc luc: %s\n", sv[i].ten, sv[i].diem, sv[i].hocLuc);
    }
}
void chucNang9() {
    int so1, so2;
    printf("Nhap 2 so du doan (tu 01 den 15): ");
    scanf("%d %d", &so1, &so2);
    srand(time(NULL));
    int kq1 = rand() % 15 + 1;
    int kq2 = rand() % 15 + 1;
    printf("Ket qua xo so he thong: %02d - %02d\n", kq1, kq2);   
    int trung = 0;
    if (so1 == kq1 || so1 == kq2) trung++;
    if (so2 == kq1 || so2 == kq2) trung++;
    if (trung == 0) printf("Chuc ban may man lan sau\n");
    else if (trung == 1) printf("Chuc mung ban da trung giai nhi\n");
    else if (trung == 2) printf("Chuc mung ban da trung giai nhat\n");
}
void rutGon(struct PhanSo *ps) {
    int gcd = getGCD(ps->tu, ps->mau);
    ps->tu /= gcd;
    ps->mau /= gcd;
    if (ps->mau < 0) {
        ps->tu = -ps->tu;
        ps->mau = -ps->mau;
    }
}
void chucNang10() {
    struct PhanSo ps1, ps2, kq;
    printf("Nhap tu so va mau so cua Phan so 1: ");
    scanf("%d %d", &ps1.tu, &ps1.mau);
    printf("Nhap tu so va mau so cua Phan so 2: ");
    scanf("%d %d", &ps2.tu, &ps2.mau);
    if (ps1.mau == 0 || ps2.mau == 0) {
        printf("Loi: Mau so phai khac 0.\n");
        return;
    }
    kq.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    kq.mau = ps1.mau * ps2.mau;
    rutGon(&kq);
    printf("Tong: %d/%d\n", kq.tu, kq.mau);
    kq.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    kq.mau = ps1.mau * ps2.mau;
    rutGon(&kq);
    printf("Hieu: %d/%d\n", kq.tu, kq.mau);
    kq.tu = ps1.tu * ps2.tu;
    kq.mau = ps1.mau * ps2.mau;
    rutGon(&kq);
    printf("Tich: %d/%d\n", kq.tu, kq.mau);
    if (ps2.tu != 0) {
        kq.tu = ps1.tu * ps2.mau;
        kq.mau = ps1.mau * ps2.tu;
        rutGon(&kq);
        printf("Thuong: %d/%d\n", kq.tu, kq.mau);
    } else {
        printf("Loi: Khong the chia vi tu so cua Phan so 2 bang 0.\n");
    }
}
#include <stdio.h>
// kiem tra so ng to
int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int arr[100], n = 0;
    
    while (1) {
        printf("\n--------MENU--------\n");
        printf("1. Nhap so phan tu va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. In ra gia tri lon nhat cua mang\n");
        printf("4. In ra cac phan tu la so nguyen to\n");
        printf("5. Them mot phan tu vao trong mang\n");
        printf("6. Xoa mot phan tu trong mang\n");
        printf("7. Sap xep mang theo thu tu tang dan\n");
        printf("8. Tim kiem phan tu va in ra vi tri index\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        
        int choice;
        scanf("%d", &choice);

        if (choice == 9) {
            printf("Thoat chuong trinh.\n");
            break;
        }

        switch (choice) {
            case 1: {
                printf("Nhap so phan tu: ");
                scanf("%d", &n);
                printf("Nhap gia tri cac phan tu:\n");
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = ", i);
                    scanf("%d", &arr[i]);
                }
                break;
            }
            
            case 2: {
                if (n == 0) {
                    printf("Mang chua duoc nhap.\n");
                    break;
                }
                printf("Gia tri cac phan tu trong mang:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            
            case 3: {
                if (n == 0) {
                    printf("Mang chua duoc nhap.\n");
                    break;
                }
                int max = arr[0];
                for (int i = 1; i < n; i++) {
                    if (arr[i] > max) max = arr[i];
                }
                printf("Gia tri lon nhat cua mang: %d\n", max);
                break;
            }
            
            case 4: {
                if (n == 0) {
                    printf("Mang chua duoc nhap.\n");
                    break;
                }
                printf("Cac phan tu la so nguyen to:\n");
                for (int i = 0; i < n; i++) {
                    if (isPrime(arr[i])) {
                        printf("%d ", arr[i]);
                    }
                }
                printf("\n");
                break;
            }
            
            case 5: {
                if (n == 0) {
                    printf("Mang chua duoc nhap.\n");
                    break;
                }
                int newElement;
                printf("Nhap phan tu moi: ");
                scanf("%d", &newElement);
                arr[n] = newElement;
                n++;
                printf("Phan tu moi da duoc them.\n");
                break;
            }
            
            case 6: {
                if (n == 0) {
                    printf("Mang chua duoc nhap.\n");
                    break;
                }
                int index;
                printf("Nhap vi tri phan tu can xoa: ");
                scanf("%d", &index);
                if (index >= 0 && index < n) {
                    for (int i = index; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    printf("Phan tu da duoc xoa.\n");
                } else {
                    printf("Vi tri xoa khong hop le.\n");
                }
                break;
            }
            
            case 7: {
                if (n == 0) {
                    printf("Mang chua duoc nhap.\n");
                    break;
                }
                
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (arr[i] > arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                printf("Mang sau khi sap xep:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 8: {
                if (n == 0) {
                    printf("Mang chua duoc nhap.\n");
                    break;
                }
                int searchElement;
                printf("Nhap phan tu can tim: ");
                scanf("%d", &searchElement);
                int found = -1;
                for (int i = 0; i < n; i++) {
                    if (arr[i] == searchElement) {
                        found = i;
                        break;
                    }
                }
                if (found != -1) {
                    printf("Phan tu %d duoc tim thay tai vi tri %d.\n", searchElement, found);
                } else {
                    printf("Phan tu khong ton tai trong mang.\n");
                }
                break;
            }
            default:
                printf("Lua chon khong hop le.\n");
                break;
        }
    }

    return 0;
}


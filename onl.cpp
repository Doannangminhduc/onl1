#include <stdio.h>

// duong cheo chinh
void sortDiagonal(int matrix[100][100], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (matrix[i][i] > matrix[j][j]) {
                int tp = matrix[i][i];
                matrix[i][i] = matrix[j][j];
                matrix[j][j] = tp;
            }
        }
    }
}

int main() {
    int matrix[100][100];
    int rows = 0, cols = 0;

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu la le va tinh tong\n");
        printf("4. In ra cac phan tu tren duong bien va tinh tich\n");
        printf("5. In ra cac phan tu tren duong cheo chinh\n");
        printf("6. In ra cac phan tu tren duong cheo phu\n");
        printf("7. Sap xep duong cheo chinh theo thu tu tang dan\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");

        int choice;
        scanf("%d", &choice);

        if (choice == 8) {
            printf("Thoat chuong trinh.\n");
            break;
        }

        switch (choice) {
        	
            case 1: {
                printf("Nhap so dong: ");
                scanf("%d", &rows);
                printf("Nhap so cot: ");
                scanf("%d", &cols);

                if (rows <= 0 || cols <= 0 || rows > 100 || cols > 100) {
                    printf("Kich thuoc khong hop le!\n");
                    rows = cols = 0;
                    break;
                }

                printf("Nhap gia tri cac phan tu cua ma tran:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("matrix[%d][%d] = ", i, j);
                        scanf("%d", &matrix[i][j]);
                    }
                }
                break;
            }
            
            case 2: {
                if (rows == 0 || cols == 0) {
                    printf("Ma tran chua duoc nhap.\n");
                    break;
                }

                printf("Ma tran:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("%d ", matrix[i][j]);
                    }
                    printf("\n");
                }
                break;
            }
            
            case 3: {
                if (rows == 0 || cols == 0) {
                    printf("Ma tran chua duoc nhap.\n");
                    break;
                }

                int sumOdd = 0;
                printf("Cac phan tu le:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (matrix[i][j] % 2 != 0) {
                            printf("%d ", matrix[i][j]);
                            sumOdd += matrix[i][j];
                        }
                    }
                }
                printf("\nTong cac phan tu le: %d\n", sumOdd);
                break;
            }
            
            case 4: {
                if (rows == 0 || cols == 0) {
                    printf("Ma tran chua duoc nhap.\n");
                    break;
                }

                int product = 1;
                printf("Cac phan tu tren duong bien:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                            printf("%d ", matrix[i][j]);
                            product *= matrix[i][j];
                        }
                    }
                }
                printf("\nTich cac phan tu tren duong bien: %d\n", product);
                break;
            }
            
            case 5: {
                if (rows == 0 || cols == 0) {
                    printf("Ma tran chua duoc nhap.\n");
                    break;
                }

                printf("Cac phan tu tren duong cheo chinh:\n");
                for (int i = 0; i < rows && i < cols; i++) {
                    printf("%d ", matrix[i][i]);
                }
                printf("\n");
                break;
            }
            
            case 6: {
                if (rows == 0 || cols == 0) {
                    printf("Ma tran chua duoc nhap.\n");
                    break;
                }

                printf("Cac phan tu tren duong cheo phu:\n");
                for (int i = 0; i < rows && i < cols; i++) {
                    printf("%d ", matrix[i][cols - i - 1]);
                }
                printf("\n");
                break;
            }
            case 7: {
                if (rows == 0 || cols == 0) {
                    printf("Ma tran chua duoc nhap.\n");
                    break;
                }

                sortDiagonal(matrix, rows);
                printf("Duong cheo chinh sau khi sap xep:\n");
                for (int i = 0; i < rows; i++) {
                    printf("%d ", matrix[i][i]);
                }
                printf("\n");
                break;
            }
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    }

    return 0;
}


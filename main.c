#include <stdio.h>

int main() {
    int available[3] = {3, 2, 2};  // Available instances of A, B, and C
    int max[3][3] = {{8, 4, 3}, {6, 2, 0}, {3, 3, 3}};  // Maximum instances required
    int allocation[3][3] = {{0, 0, 1}, {3, 2, 0}, {2, 1, 1}};  // Current allocation
    int request[3][3];  // Request matrix
    int work[3];  // Work vector
    int finish[3] = {0, 0, 0};  // Finish vector
    int n = 3;  // Number of processes
    int m = 3;  // Number of resources

    // Get the request matrix from the user
    printf("Enter the request for P0 (A B C): ");
    scanf("%d %d %d", &request[0][0], &request[0][1], &request[0][2]);

    printf("Enter the request for P1 (A B C): ");
    scanf("%d %d %d", &request[1][0], &request[1][1], &request[1][2]);

    // Initialize work to available
    for (int i = 0; i < m; i++) {
        work[i] = available[i];
    }

    // Check if the request is less than or equal to need and available resources
    for (int i = 0; i < n; i++) {
        if (!finish[i] &&
            request[i][0] <= max[i][0] - allocation[i][0] &&
            request[i][1] <= max[i][1] - allocation[i][1] &&
            request[i][2] <= max[i][2] - allocation[i][2]) {
            // Simulate resource allocation
            for (int j = 0; j < m; j++) {
                work[j] -= request[i][j];
                allocation[i][j] += request[i][j];
                available[j] -= request[i][j];
            }

            finish[i] = 1;
        }
    }

    // Check if the system is in a safe state
    int safe = 1;
    for (int i = 0; i < n; i++) {
        if (!finish[i]) {
            safe = 0;
            break;
        }
    }

    if (safe) {
        printf("The system is in a safe state.\n");
    } else {
        printf("The system is not in a safe state.\n");
    }

    return 0;
}


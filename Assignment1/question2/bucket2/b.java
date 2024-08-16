import java.util.Arrays;

public class b {
    public static void main(String[] args) {
        int[] ns = {64, 128, 256, 512, 1024};

        for (int n : ns) {
            long[][] A = new long[n][n];
            long[][] B = new long[n][n];
            long[][] result = new long[n][n];

            // Initialize matrices A and B
            for (int i = 0; i < n; i++) {
                Arrays.fill(A[i], 1);
                Arrays.fill(B[i], 1);
            }

            long startTime = System.nanoTime();

            // Perform matrix multiplication
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        result[i][j] += A[i][k] * B[k][j];
                    }
                }
            }

            long endTime = System.nanoTime();
            double timeTaken = (endTime - startTime) / 1e9; // Convert nanoseconds to seconds
            System.out.println("N = " + n + ", Time taken = " + timeTaken + " seconds");
        }
    }
}
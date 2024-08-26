import java.io.*;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		int N = Integer.parseInt(r.readLine());
		StringTokenizer st = new StringTokenizer(r.readLine());
		int[] H = new int[N];
		for (int i = 0; i < N; i++) {
			H[i] = Integer.parseInt(st.nextToken());
		}

		int[] dp = new int[N];
		for (int i = 0; i < N; i++) {
			dp[i] = Integer.MAX_VALUE;
		}

		dp[0] = 0;
		for (int i = 1; i < N; i++) {
			if (i - 1 >= 0) {
				dp[i] = Math.min(dp[i], dp[i-1] + Math.abs(H[i] - H[i-1]));
			}

			if (i - 2 >= 0) {
				dp[i] = Math.min(dp[i], dp[i-2] + Math.abs(H[i] - H[i-2]));
			}
		}

		pw.println(dp[N-1]);

		pw.close();
	}
}

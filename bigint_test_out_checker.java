import java.util.*;
import java.io.*;

public class bigint_test_out_checker {
	public static void main (String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("bigint_test_out.txt")));
		StringTokenizer st;
		String line;
		int a, b, correct_ans, ans;
		
		while ( (line = in.readLine()) != null ) {
			st = new StringTokenizer(line);
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			correct_ans = Integer.parseInt(st.nextToken());
			line = st.nextToken();
			try {
				ans = Integer.parseInt(line);
				if (ans != correct_ans) {
					System.out.println("a + b = " + correct_ans + " (not " + ans + ")");
				}
			} catch (Exception e) {
				System.out.println("a + b = " + correct_ans + " (not " + line + ")");
			}
		}
	}
}

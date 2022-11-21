import java.util.*;
import java.io.*;

public class bigint_test_out_checker {
	public static void main (String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("bigint_test_out.txt")));
		StringTokenizer st;
		String line;
		int a, b, correct_ans, ans;
		int line_num = 0;
		while ( (line = in.readLine()) != null ) {
			++ line_num;
			st = new StringTokenizer(line);
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			correct_ans = Integer.parseInt(st.nextToken());
			try {
				line = st.nextToken();
			} catch (Exception e) {
				System.err.println("Incorrect format of line: " + line_num);
				System.err.println(line);
				System.exit(1);
			}
			if (line.contains("-0") || (line.length() > 1 && line.charAt(0) == '0')) {
				System.out.println(a + " op " + b + " = " + correct_ans + " (not " + line + ")");
			} else {
				try {
					ans = Integer.parseInt(line);
					if (ans != correct_ans) {
						System.out.println(a + " op " + b + " = " + correct_ans + " (not " + ans + ")");
					}
				} catch (Exception e) {
					System.out.println(a + " op " + b + " = " + correct_ans + " (not " + line + ")");
				}
			}
		}
	}
}

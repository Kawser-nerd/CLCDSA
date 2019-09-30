using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam {

	class Number {
		const int N = 100;
		int[] digits = new int[N];
		public Number(string number) {
			Array.Clear(digits, 0, digits.Length);
			for (int i = 0; i < number.Length; i++) {
				int digit = number[number.Length - 1 - i] - '0';
				digits[i] = digit;
			}
		}
		public Number(Number number) {
			Array.Copy(number.digits, digits, N);
		}
		public Number(Number number, int leftShift) {
			for (int i = 0; i < N; i++) {
				int j = i - leftShift;
				int digit = j >= 0 ? number.digits[j] : 0;
				digits[i] = digit;
			}
		}

		public bool IsZero() {
			for (int i = 0; i < N; i++)
				if (digits[i] != 0) return false;
			return true;
		}
		public static int Compare(Number a, Number b) {
			for (int i = N - 1; i >= 0; i--) {
				int delta = a.digits[i] - b.digits[i];
				if (delta < 0) return -1;
				if (delta > 0) return 1;
			}
			return 0;
		}
		public static Number AbsDifference(Number a, Number b) {
			int c = Compare(a, b);
			if (c < 0) {
				Number t = new Number(b);
				t.Subtract(a);
				return t;
			} else {
				Number t = new Number(a);
				t.Subtract(b);
				return t;
			}
		}

		public void Subtract(Number b) {
			for (int i = 0; i < N; i++) {
				digits[i] -= b.digits[i];
				if (digits[i] < 0) {
					digits[i] += 10;
					digits[i + 1]--;
				}
			}
		}
		public int MostSignificantDigit() {
			for (int i = N - 1; i >= 0; i--) if (digits[i] != 0) return i;
			return 0;
		}
		public static Number FastMod(Number a, Number b) {
			a = new Number(a);  // clone;
			b = new Number(b);  // clone;
			while (true) {
				string ss = a.ConvertToString();
				string tt = b.ConvertToString();
				if (Number.Compare(a, b) < 0)
					return new Number(a);

				int aMSD = a.MostSignificantDigit();
				int bMSD = b.MostSignificantDigit();
				if (aMSD < bMSD) throw new Exception();
				int shift = aMSD - bMSD;
				if (a.digits[aMSD] <= b.digits[bMSD])
					shift--;  // conservative;
				if (shift < 0) shift = 0;
				if (shift == 0) {
					a.Subtract(b);  // simple;
				} else {
					a.Subtract(new Number(b, shift));
				}
			}
		}
		public string ConvertToString() {
			if (IsZero()) return "0";
			string s = null;
			for (int i = N - 1; i >= 0; i--) {
				if (s == null && digits[i] == 0) {
					;
				} else if (s == null) {
					s = digits[i].ToString();
				} else {
					s += digits[i].ToString();
				}
			}
			return s;
		}
	}

	class Program {

		static Number gcd(Number a, Number b) {
			a = new Number(a);  // clone;
			b = new Number(b);  // clone;
			while (!b.IsZero()) {
				string ss = a.ConvertToString();
				string tt = b.ConvertToString();
				Number t = new Number(b);
				b = Number.FastMod(a, b);
				a = t;
			}
			return a;
		}

		static void Main(string[] args) {
			StreamReader sr = File.OpenText(args[0]);
			StreamWriter sw = File.CreateText(args[1]);
			string[] tokens = sr.ReadLine().Split();
			int count = int.Parse(tokens[0]);
			Number[] numbers = new Number[2000];
			for (int i = 0; i < count; i++) {
				tokens = sr.ReadLine().Split();
				int N = int.Parse(tokens[0]);
				for (int j = 0; j < N; j++) numbers[j] = new Number(tokens[j + 1]);

				Number g = Number.AbsDifference(numbers[0], numbers[1]);
				for (int j = 2; j < N; j++) g = gcd(g, Number.AbsDifference(numbers[0], numbers[j]));

				Number mod = Number.FastMod(numbers[0], g);
				Number answer;
				if (mod.IsZero()) {
					answer = mod;  // zero;
				} else {
					Number gap = new Number(g);
					gap.Subtract(mod);
					answer = gap;
				}
				sw.WriteLine("Case #" + (1 + i).ToString() + ": " + answer.ConvertToString());
			}
			sr.Close();
			sw.Close();
		}
	}
}

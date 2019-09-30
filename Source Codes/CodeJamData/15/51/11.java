import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int caseNum = 1; caseNum <= numCases; caseNum++) {
            int N = sc.nextInt();
            int D = sc.nextInt();
            int[] S = new int[N];
            int[] M = new int[N];
            int[] manager = new int[N];

            S[0] = sc.nextInt();
            int As = sc.nextInt();
            int Cs = sc.nextInt();
            int Rs = sc.nextInt();

            M[0] = sc.nextInt();
            int Am = sc.nextInt();
            int Cm = sc.nextInt();
            int Rm = sc.nextInt();

            Map<Integer, List<Integer>> reports = new HashMap<>();
            Employee[] employees = new Employee[N];
            employees[0] = new Employee(0, S[0], -1);
            for (int i = 1; i < N; i++) {
                S[i] = (S[i - 1] * As + Cs) % Rs;
                M[i] = (M[i - 1] * Am + Cm) % Rm;
                manager[i] = M[i] % i;
                employees[i] = new Employee(i, S[i], manager[i]);
                if (!reports.containsKey(manager[i])) {
                    reports.put(manager[i], new ArrayList<Integer>());
                }
                reports.get(manager[i]).add(i);
            }

            Arrays.sort(employees);

            int index = 0;
            int excludedIndex = -1;
            while (employees[index].id != 0) {
                if (employees[index].salary < S[0] - D) {
                    excludedIndex = index;
                }
                index++;
            }
            int firstIncludedIndex = excludedIndex + 1;

            boolean[] kept = new boolean[N];
            int employeesKept = 0;
            Deque<Integer> stack = new ArrayDeque<Integer>();
            stack.push(0);
            while (!stack.isEmpty()) {
                int id = stack.pop();
                kept[id] = true;
                employeesKept++;
                if (!reports.containsKey(id)) {
                    continue;
                }
                for (int reportId : reports.get(id)) {
                    if (S[0] - D <= S[reportId] && S[reportId] <= S[0]) {
                        stack.push(reportId);
                    }
                }
            }
            int max = employeesKept;

            while (index < N) {
                int nextMaxSalary = employees[index].salary;
                if (nextMaxSalary > S[0] + D) {
                    break;
                }
                while (employees[firstIncludedIndex].salary < nextMaxSalary - D) {
                    // Remove firstIncludedIndex
                    if (kept[employees[firstIncludedIndex].id]) {
                        stack = new ArrayDeque<Integer>();
                        stack.push(employees[firstIncludedIndex].id);
                        while (!stack.isEmpty()) {
                            int id = stack.pop();
                            employeesKept--;
                            kept[id] = false;
                            if (!reports.containsKey(id)) {
                                continue;
                            }
                            for (int reportId : reports.get(id)) {
                                if (kept[reportId]) {
                                    stack.push(reportId);
                                }
                            }
                        }
                    }
                    firstIncludedIndex++;
                }

                while (index < N && employees[index].salary == nextMaxSalary) {
                    // Add index
                    if (!kept[employees[index].id] && employees[index].manager != -1 && kept[employees[index].manager]) {
                        stack = new ArrayDeque<Integer>();
                        stack.push(employees[index].id);
                        while (!stack.isEmpty()) {
                            int id = stack.pop();
                            employeesKept++;
                            kept[id] = true;
                            if (!reports.containsKey(id)) {
                                continue;
                            }
                            for (int reportId : reports.get(id)) {
                                if (nextMaxSalary - D <= S[reportId] && S[reportId] <= nextMaxSalary) {
                                    stack.push(reportId);
                                }
                            }
                        }
                    }
                    index++;
                }
                max = Math.max(max, employeesKept);
            }

            System.out.println("Case #" + caseNum + ": " + max);
        }
    }

    private static class Employee implements Comparable<Employee> {
        private final int id;
        private final int salary;
        private final int manager;

        public Employee(int id, int salary, int manager) {
            this.id = id;
            this.salary = salary;
            this.manager = manager;
        }

        @Override
        public int compareTo(Employee o) {
            if (salary != o.salary) {
                return Integer.compare(salary, o.salary);
            }
            return Integer.compare(id, o.id);
        }

        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + id;
            result = prime * result + manager;
            result = prime * result + salary;
            return result;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) {
                return true;
            }
            if (obj == null) {
                return false;
            }
            if (getClass() != obj.getClass()) {
                return false;
            }
            Employee other = (Employee) obj;
            if (id != other.id) {
                return false;
            }
            if (manager != other.manager) {
                return false;
            }
            if (salary != other.salary) {
                return false;
            }
            return true;
        }

        @Override
        public String toString() {
            return "Employee [id=" + id + ", salary=" + salary + ", manager=" + manager + "]";
        }
    }
}

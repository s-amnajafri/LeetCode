/* Write your PL/SQL query statement below */
SELECT E.name AS Employee FROM Employee E JOIN Employee M ON E.managerID = M.id WHERE E.salary > M.salary;
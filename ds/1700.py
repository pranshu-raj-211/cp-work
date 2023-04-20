# fastest solution
class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        studentsQueue = collections.deque(students)
        sandwichesQueue = collections.deque(sandwiches)
        times = len(studentsQueue)
        while len(studentsQueue) > 0 and times > 0:
            if studentsQueue[0] == sandwichesQueue[0]:
                studentsQueue.popleft()
                sandwichesQueue.popleft()
                times = len(studentsQueue)
            else:
                i = studentsQueue.popleft()
                studentsQueue.append(i)
                times -= 1
        return len(studentsQueue)


# slightly slower approach
class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        while sandwiches:
            if students[0] == sandwiches[0]:
                students.pop(0)
                sandwiches.pop(0)
            else:
                student = students.pop(0)
                students.append(student)
                if sandwiches[0] not in students:
                    return len(students)
        return 0

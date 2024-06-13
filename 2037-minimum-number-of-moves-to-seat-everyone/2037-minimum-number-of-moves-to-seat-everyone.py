class Solution:
    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
        sum_moves = 0
        for student, seat in zip(sorted(students), sorted(seats)):
            sum_moves += abs(student-seat)
        return sum_moves
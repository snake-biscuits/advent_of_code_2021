# depths = [199, 200, 208, 210, 200, 207, 240, 269, 260, 263]  # example

with open("depths.txt") as depths_file:
    depths = [*map(int, depths_file.readlines())]

increases = 0

previous_window_sum = sum(depths[0:3])
for i in range(len(depths) - 2):
    window_sum = sum(depths[i:i + 3])
    if window_sum > previous_window_sum:
        increases += 1
    previous_window_sum = window_sum

print(increases)

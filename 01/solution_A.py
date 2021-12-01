# depths = [199, 200, 208, 210, 200, 207, 240, 269, 260, 263]  # example

with open("depths.txt") as depths_file:
    depths = [*map(int, depths_file.readlines())]


increases = 0
previous_depth = depths[0]
for depth in depths[1:]:
    if depth > previous_depth:
        increases += 1
    previous_depth = depth


print(increases)
    

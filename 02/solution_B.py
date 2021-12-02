# directions = ["forward 5", "down 5", "forward 8", "up 3", "down 8" , "forward 2"]

with open("directions.txt") as input_file:
    directions = list(input_file.readlines())


horizontal_position, depth = 0, 0
aim = 0
for direction, x in map(str.split, directions):
    x = int(x)
    if direction == "forward":
        horizontal_position += x
        depth += aim * x
    elif direction == "back":
        horizontal_position -= x
    elif direction == "down":
        aim += x
    elif direction == "up":
        aim -= x

print(f"{horizontal_position = }, {depth = }")
print(f"solution = {horizontal_position * depth}")
        

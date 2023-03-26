from dataclasses import dataclass
from typing import List
import sqlite3

@dataclass
class RangeLine:
	type: int
	q: float
	v: int
	a_zone: List[float]
	b_zone: List[float]
	c_zone: List[float]
	d_zone: List[float]
	
def get_range(splited_line, index):
	try:
		return splited_line[index].split("-")
	except Exception:
		return [0,0]

with open("zone.txt", "r") as file:
	r_list = list()
	for line in file:
		splited_line = line.split()
		r_line = RangeLine(
			splited_line[0], 
			splited_line[1],
			splited_line[2],
			get_range(splited_line, 3),
			get_range(splited_line, 4),
			get_range(splited_line, 5),
			get_range(splited_line, 6),
		)
		r_list.append(r_line)

	conn = sqlite3.connect('database.sqlite3')
	cursor = conn.cursor()
	for i in r_list:
		cursor.execute(f"INSERT INTO range VALUES ({i.type},{i.q},{i.v},{i.a_zone[0]},{i.a_zone[1]},{i.b_zone[0]},{i.b_zone[1]},{i.c_zone[0]},{i.c_zone[1]},{i.d_zone[0]},{i.d_zone[1]});")
		conn.commit()



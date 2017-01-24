#include <iostream>
#include <cstring>
using namespace std;

bool labyrinthTraverse(char lab[][5], int x, int y, int currentT, int maxT) {
	// Проверяваме дали не сме излезли от рамките на лабиринта
	if (x < 0 || y < 0 || x > 4 || y > 4)
		return false;
	
	// Ако сме на правилната позиция и точния брой жълтици, завършваме успешно
	if (x == 4 && y == 4 && currentT == maxT)
		return true;
	
	// Ако сме на изхода, но нямаме достатъчно жълтици, връщаме лъца
	if (x == 4 && y == 4 && currentT < maxT)
		return false;
	
	// Ако новата ни позиция е непроходима, връщаме лъжа
	if (lab[x][y] == '#')
		return false;
	
	// Ако сме намерили нова жълтица, увеличаваме текущия брой
	if (lab[x][y] == '$')
		currentT++;

	// Запазваме текущата стойност на клетката (може да е жълтица или ' ')
	// и "срутваме тавана" на съшата клетка
	char temp = lab[x][y];
	lab[x][y] = '#';
	
	// Пробваме рекурсивно да намерим решение, тръгвайки в четирите посоки
	if (labyrinthTraverse(lab, x + 1, y, currentT, maxT))
		return true;
	if (labyrinthTraverse(lab, x - 1, y, currentT, maxT))
		return true;	
	if (labyrinthTraverse(lab, x, y + 1, currentT, maxT))
		return true;
	if (labyrinthTraverse(lab, x, y - 1, currentT, maxT))
		return true;

	// Не сме успели да намерим решение, трябва да възстановим предишната стойност на клетката и да върнем лъжа.
	// Няма нужда да намаляваме текущия брой жълтици, тъй като той се подава по копие и автоматично ще се възстанови
	// при връщането.
	lab[x][y] = temp;
	return false;
}

void center(char* str) {
	int left = 0;
	int right = 0;
	int i = 0;
	int len = strlen(str);
	
	while (str[i++] == ' ')
		left++;
	
	i = len - 1;
	while (str[i--] == ' ')
		right++;
	
	// Ако има повече интервали в началото, отколкото в края,
	// то ще преместим "същинския" низ на правилната позиция,
	// започвайки от началото му.
	if (left > right + 1) {
		int current = (left + right) / 2;

		for (int j = left; j < len - right; j++) {
			str[current++] = str[j];
			// Това е необходимо, за да заличим следите от символа в същинския низ,
			// който досега е бил на тази позиция.
			str[j] = ' ';
		}
	}
	// Ако пък има повече интервали в края, отколкото в началото,
	// то ще преместим "същинския" низ, започвайки от края му.
	if (left + 1 < right) {
		int current = len - (left + right) / 2;
		
		for (int j = len - right; j >= left; j--) {
			str[current--] = str[j];
			str[j] = ' ';
		}
	}
}

void removeDuplications(char* str) {
	// На позиция i ще пазим дали символ с ASCII код i се е срещал вече в низа
	bool symbolOccured[256];
	for (int i = 0; i < 256; i++)
		symbolOccured[i] = false;

	int len = strlen(str);
	// current е текущата позиция, на която трябва да се запише следващият символ,
	// който не се е срещал досега
	int current = 0;

	for (int i = 0; i < len; i++) {
		if (!symbolOccured[str[i]]) {
			symbolOccured[str[i]] = true;
			str[current++] = str[i];
		}
	}

	// Отсиваме низа, докъдето сме стигнали
	str[current] = '\0';
}

int main() {
	char labyrinth[5][5];
	char path[100];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			labyrinth[i][j] = ' ';
	
	int max = 3;
	
	labyrinth[2][1] = labyrinth[2][2] = labyrinth[2][3] =  labyrinth[2][4] = labyrinth[4][1] = '#';
	labyrinth[0][3] = labyrinth[2][0] = labyrinth[4][0] = '$';
	
	cout << labyrinthTraverse(labyrinth, 0, 0, 0, max) << endl;
	
	char x[20] = "  abc            ";
	center(x);
	cout << x << "X" << endl;
	
	char y[20] = "abc dae fhc";
	removeDuplications(y);
	cout << y << endl;
}
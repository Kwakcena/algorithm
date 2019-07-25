#include <iostream>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	for(int i=1; i<=T; i++) {
		//현재 박수 치는 사람, 
		int clapPeople = 0, employment = 0;
		char *str = new char[1005];

		scanf("%s", str);
		clapPeople = *str - 48;

		for(int j=1; *(str + j) != '\0'; j++) {
			int strToInt = *(str + j) - 48;

			//J+1 번째 인원이 현재 박수치는 인원보다 많아야 박수를 침. 
			if(clapPeople >= j) {
				clapPeople += number;
			}
			else {

				int temp = (j - clapPeople);
				employment += temp;
				clapPeople += (temp + strToInt);
			}
		}

		printf("#%d %d\n", i, employment);
		delete str;
	}


	return 0;
}

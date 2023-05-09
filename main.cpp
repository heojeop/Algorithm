#include <regex>
#include <iostream>
#include <string>


void Pn() {
	std::regex PN("^(?:\\+\\d{1,3})?[- ]?\\d{2,3}[- ]\\d{3,4}[- ]\\d{4}$");
	std::string PhoneNumber;

	while (1)
	{
		printf("전화번호를 입력 해 주세요 = ");
		std::getline(std::cin, PhoneNumber);

		if (std::regex_match(PhoneNumber, PN)) {
			printf("전화번호 형식이 올바릅니다.\n");
			break;
		}
		else
		{
			printf("전화번호 형식이 올바르지 않습니다.\n");
		}
	}
}

void email() {

	std::regex EM("^[0-9a-zA-Z]([-_\.]?[0-9a-zA-Z])*@[0-9a-zA-Z]([-_\.]?[0-9a-zA-Z])*\.[a-zA-Z]{2,3}$");
	std::string Email;

	while (1)
	{
		printf("이메일을 입력 해 주세요 = ");
		std::getline(std::cin, Email);

		if (std::regex_match(Email, EM)) {
			printf("이메일 형식이 올바릅니다.\n");

		}
		else
		{
			printf("이메일 형식이 올바르지 않습니다.\n");
		}
	}
}

void Password() {
	std::regex PW("^(?=.*[A-Z])(?=.*[a-z])(?=.*\\d)(?=.*[!@#$%^&*])[A-Za-z\\d!@#$%^&*]{8,}$");
	std::string Password;

	while (1)
	{
		printf("비밀번호를 입력 해 주세요 = ");
		std::getline(std::cin, Password);

		if (std::regex_match(Password, PW)) {
			printf("비밀번호 형식이 올바릅니다.\n");

		}
		else
		{
			printf("비밀번호 형식이 올바르지 않습니다.\n");
		}
	}
}
int main(void) {
	

	Password();



}



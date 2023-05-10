#include <regex>
#include <iostream>
#include <string>


void Pn() {
	std::regex PN("^(?:\\+\\d{1,3})?[- ]?\\d{2,3}[- ]\\d{3,4}[- ]\\d{4}$");
	std::string PhoneNumber;

	while (1)
	{
		printf("��ȭ��ȣ�� �Է� �� �ּ��� = ");
		std::getline(std::cin, PhoneNumber);

		if (std::regex_match(PhoneNumber, PN)) {
			printf("��ȭ��ȣ ������ �ùٸ��ϴ�.\n");
			break;
		}
		else
		{
			printf("��ȭ��ȣ ������ �ùٸ��� �ʽ��ϴ�.\n");
		}
	}
}

void email() {

	std::regex EM("^[0-9a-zA-Z]([-_\.]?[0-9a-zA-Z])*@[0-9a-zA-Z]([-_\.]?[0-9a-zA-Z])*\.[a-zA-Z]{2,3}$");
	std::string Email;

	while (1)
	{
		printf("�̸����� �Է� �� �ּ��� = ");
		std::getline(std::cin, Email);

		if (std::regex_match(Email, EM)) {
			printf("�̸��� ������ �ùٸ��ϴ�.\n");

		}
		else
		{
			printf("�̸��� ������ �ùٸ��� �ʽ��ϴ�.\n");
		}
	}
}

void Password() {
	std::regex PW("^(?=.*[A-Z])(?=.*[a-z])(?=.*\\d)(?=.*[!@#$%^&*])[A-Za-z\\d!@#$%^&*]{8,}$");
	std::string Password;

	while (1)
	{
		printf("��й�ȣ�� �Է� �� �ּ��� = ");
		std::getline(std::cin, Password);

		if (std::regex_match(Password, PW)) {
			printf("��й�ȣ ������ �ùٸ��ϴ�.\n");

		}
		else
		{
			printf("��й�ȣ ������ �ùٸ��� �ʽ��ϴ�.\n");
		}
	}
}
#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

class StructTest
{
	static struct logradouro
	{
		std::string rua;
		std::string bairro;
		std::string complemento;
		int numero;
		int cep;
		char uf[2];

		bool operator ==(const logradouro& log) const
		{
			return this->rua == log.rua &&
				this->bairro == log.bairro &&
				this->complemento == log.complemento &&
				this->numero == log.numero &&
				this->cep == log.cep &&
				strcmp(this->uf, log.uf) == 0;
		}
	};

	static struct cliente
	{
		std::string nome;
		char genero;
		int idade;

		logradouro endereco;

		bool operator ==(const cliente& cli) const
		{
			return this->nome == cli.nome &&
				this->genero == cli.genero &&
				this->idade == cli.idade &&
				this->endereco == cli.endereco;
		}
	};

	using clientes = std::vector<cliente>;

	clientes m_clientes;

public:
	StructTest()
	{
		m_clientes.reserve(0);
	}

	StructTest(const StructTest& source) = default;
	StructTest(StructTest&& source) = default;
	StructTest& operator =(const StructTest& source) = default;
	StructTest& operator =(StructTest&& source) = default;
	~StructTest() = default;

	clientes get_clientes() const { return m_clientes; }
	void add_cliente(cliente cliente) { m_clientes.push_back(cliente); }
	bool remove_cliente(cliente cl) { m_clientes.erase(std::remove_if(m_clientes.begin(), m_clientes.end(), [&cl](cliente cli) {return cl == cli; })); }
	int qtde_de_clientes() const { return std::size(m_clientes); }
};


# Graos do Vale🌱
System for Grain Cargo Management

This software, developed in C, is designed to manage grain cargoes within a cooperative.

The program reads files containing data collected by sensors, including humidity, weight, impurity levels, and product type, among other parameters.
It processes this data, storing it in a database, and generates monthly, yearly, individual, and statistical reports based on the stored information.

# Grão do Vale🌱
Cooperativa Agrícola
Sistema de Gerenciamento de Cargas de Grãos

Este software, desenvolvido em C, foi projetado para gerenciar cargas de grãos em uma cooperativa.

O programa lê arquivos contendo dados coletados por sensores, incluindo umidade, peso, níveis de impureza e tipo de produto, entre outros parâmetros.
Ele processa esses dados, armazenando-os em um banco de dados, e gera relatórios mensais, anuais, individuais e estatísticos com base nas informações armazenadas.

## Como utilizar:

**compilação geral**: 
Vá até a pasta ./bin e compile usando o codigo abaixo:
g++ ../src/main.c ../src/carregamento.c ../src/leitura.c ../src/relatorios.c ../src/escrevedb.c -o programa -I../include

**Server API**: 
Com o python instalado, vá até a pasta API e execute:
python app.py. <br></br>
Caso queira, se pesquisar "localhost:5000/dados" no navegador, será possível ver os dados que estão sendo exportados no endpoint /dados

## Front-end 
Para consumir a api e utilizar os dados no front-end basta abrir o repositório https://github.com/murilorrs/Cooperativa-Agricola-React e executar o programa com **npm run dev**, o que irá disponibilizar um link "localhost:xxxx" no terminal, que uma vez aberto, mostrará os relatórios da cooperativa. Lembrando que o servidor da API deve estar ligado para isso.


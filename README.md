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

compilação: g++ ../src/main.c ../src/carregamento.c ../src/leitura.c ../src/relatorios.c ../src/escrevedb.c -o programa -I../include
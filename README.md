<h1 align="center"><img src="./Pic/favicon.ico" width="64" align="center"> Re-AsulCFGManager (ACM)</h1>

<p align="center">
    <a href="https://acm.asul.top/">
        <img alt="Static Badge" src="https://img.shields.io/badge/website-ACM-blue?style=for-the-badge">
    </a>
    <a href="https://github.com/AsulTop/Re-AsulCFGManager/pulse">
        <img alt="GitHub commit activity" src="https://img.shields.io/github/commit-activity/m/AsulTop/AsulCFGManager?style=for-the-badge">
    </a>
</p>
<p align="center">
    <a href="https://github.com/AsulTop/Re-AsulCFGManager">
        <img alt="Static Badge" src="https://img.shields.io/badge/Re-AsulCFGManager-Main?style=for-the-badge&logo=github&labelColor=green&color=green">
    </a>
    <!-- <a href="https://github.com/eLecCap1taL/AutoSettings">
        <img alt="Static Badge" src="https://img.shields.io/badge/Manager-Manager?style=for-the-badge&logo=github&labelColor=yellow&color=yellow">
    </a> -->
    <a href="https://github.com/AsulTop/Asultop.github.io">
        <img alt="Static Badge" src="https://img.shields.io/badge/Page-Page?style=for-the-badge&logo=github&labelColor=purple&color=purple">
    </a>
</p>

<p align="center">
    <a href="#english-version"><strong>English</strong></a> | 
    <a href="#russian-version"><strong>Русский</strong></a> | 
    <a href="#chinese-version"><strong>中文</strong></a>
</p>

---

## English Version

# Re-AsulCFGManager - CS2 Configuration Management Tool

## Project Overview

**Re-AsulCFGManager** is an efficient, user-friendly configuration management tool designed specifically for Counter-Strike 2 (CS2). This tool supports importing, parsing, and managing game configuration files (CFG), aiming to enhance players' gaming experience and setting management efficiency.

## Key Features

- **Package Import**: Easily import pre-prepared CS2 configuration packages.
- **Auto Parsing**: Intelligently parse package content and automatically copy configuration files to specified locations.
- **Simple Management**: Quickly switch and update configuration files through an intuitive interface to adapt to different gaming needs.

## Requirements

- **Operating System**: Windows, macOS, or Linux
- **Qt 6.3.x or above**: Used for project building and interface display.
- **C++ Compiler**: GCC or MSVC recommended, ensuring support for C++11 or above.

## Installation & Build Guide

### Clone Project

```bash
git clone https://github.com/Asultop/AsulCFGManager.git
cd AsulCFGManager
cd ElaWidgetTool
```

### Build Project

1. Compile ElaWidgetTool
2. Open `CMakeList.txt` with Qt Creator
3. Or build through CMake
4. Place the compiled `elawidgettools.dll` in the parent directory `../dll`
5. Return to parent directory:
   ```bash
   mkdir build
   cd build
   cmake .. -G "MinGW Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release
   ```
6. Open `AsulCFGManager.pro` with Qt Creator, configure compilation options.
7. Or build via command line:
   ```bash
   qmake AsulCFGManager.pro
   make
   ```

### Run Program

After building, execute the generated executable file to start the program.

## Usage Instructions

1. Launch Re-AsulCFGManager.
2. Click "Import Configuration" and select the prepared CS2 installation package.
3. The tool will automatically parse and copy configuration files to the game configuration directory.
4. Use interface features to quickly switch and apply the required configuration.

## Project Structure

- **Sources/**: Contains all source code files.
- **Headers/**: Stores project header files.
- **Tools/**: Additional tools and utilities.
- **lib/**: Dependency libraries and external resources.
- **Resources/**: Contains icons and other static resources.
- **FluentCSRM.pro**: Qt project file defining build settings.

## Contributing

Community participation is welcome! If you wish to contribute code or suggest improvements, please:

1. Fork this project.
2. Create a new branch for your changes.
3. Submit a Pull Request describing your changes and improvements.

## Contact Information

For questions or suggestions, please contact us through [Issues](https://github.com/Asultop/AsulCFGManager/issues).

---

## Russian Version

# Re-AsulCFGManager - Инструмент управления конфигурациями CS2

## Обзор проекта

**Re-AsulCFGManager** - это эффективный и удобный инструмент управления конфигурациями, разработанный специально для Counter-Strike 2 (CS2). Этот инструмент поддерживает импорт, анализ и управление игровыми конфигурационными файлами (CFG), направленный на улучшение игрового опыта и эффективности управления настройками.

## Основные функции

- **Импорт пакетов**: Легко импортировать подготовленные пакеты конфигураций CS2.
- **Автоанализ**: Умный анализ содержимого пакетов и автоматическое копирование конфигурационных файлов в указанные места.
- **Простое управление**: Быстрая смена и обновление конфигурационных файлов через интуитивно понятный интерфейс для адаптации к разным игровым потребностям.

## Требования

- **Операционная система**: Windows, macOS или Linux
- **Qt 6.3.x или выше**: Используется для сборки проекта и отображения интерфейса.
- **Компилятор C++**: Рекомендуется GCC или MSVC, обеспечивающий поддержку C++11 или выше.

## Руководство по установке и сборке

### Клонирование проекта

```bash
git clone https://github.com/Asultop/AsulCFGManager.git
cd AsulCFGManager
cd ElaWidgetTool
```

### Сборка проекта

1. Скомпилируйте ElaWidgetTool
2. Откройте `CMakeList.txt` в Qt Creator
3. Или соберите через CMake
4. Поместите скомпилированный `elawidgettools.dll` в родительскую директорию `../dll`
5. Вернитесь в родительскую директорию:
   ```bash
   mkdir build
   cd build
   cmake .. -G "MinGW Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release
   ```
6. Откройте `AsulCFGManager.pro` в Qt Creator, настройте параметры компиляции.
7. Или соберите через командную строку:
   ```bash
   qmake AsulCFGManager.pro
   make
   ```

### Запуск программы

После сборки выполните сгенерированный исполняемый файл для запуска программы.

## Инструкции по использованию

1. Запустите Re-AsulCFGManager.
2. Нажмите "Импортировать конфигурацию" и выберите подготовленный пакет установки CS2.
3. Инструмент автоматически проанализирует и скопирует конфигурационные файлы в директорию конфигурации игры.
4. Используйте функции интерфейса для быстрой смены и применения нужной конфигурации.

## Структура проекта

- **Sources/**: Содержит все исходные коды.
- **Headers/**: Хранит заголовочные файлы проекта.
- **Tools/**: Дополнительные инструменты и утилиты.
- **lib/**: Библиотеки зависимостей и внешние ресурсы.
- **Resources/**: Содержит иконки и другие статические ресурсы.
- **FluentCSRM.pro**: Файл проекта Qt, определяющий настройки сборки.

## Вклад в развитие

Приветствуется участие сообщества! Если вы хотите внести код или предложить улучшения, пожалуйста:

1. Сделайте Fork этого проекта.
2. Создайте новую ветку для изменений.
3. Отправьте Pull Request с описанием ваших изменений и улучшений.

## Контактная информация

По вопросам или предложениям, пожалуйста, свяжитесь с нами через [Issues](https://github.com/Asultop/AsulCFGManager/issues).

---

## Chinese Version

# Re-AsulCFGManager - CS2 配置管理工具

## 项目简介

**Re-AsulCFGManager** 是一个高效、用户友好的配置管理工具，专为《反恐精英 2》（CS2）设计。该工具支持导入、解析和管理游戏配置文件（CFG），旨在提升玩家的游戏体验和设置管理效率。

## 主要功能

- **安装包导入**：轻松导入预先准备的 CS2 配置安装包。
- **自动解析**：智能解析安装包内容，自动将配置文件复制到指定位置。
- **简便管理**：通过直观界面，快速切换和更新配置文件，适应不同的游戏需求。

## 环境要求

- **操作系统**：Windows, macOS, 或 Linux
- **Qt 6.3.x 或以上**：用于项目构建与界面展示。
- **C++ 编译器**：推荐使用 GCC 或 MSVC，确保支持 C++11 或以上标准。

## 安装与构建指南

### 克隆项目

```bash
git clone https://github.com/Asultop/AsulCFGManager.git
cd AsulCFGManager
cd ElaWidgetTool
```

### 构建项目

1. 编译 ElaWidgetTool
2. 使用 Qt Creator 打开 `CMakeList.txt`
3. 或通过 CMake 构建
4. 将编译获得的 `elawidgettools.dll` 放入父目录 `../dll`
5. 返回到父目录：
   ```bash
   mkdir build
   cd build
   cmake .. -G "MinGW Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release
   ```
6. 使用 Qt Creator 打开 `AsulCFGManager.pro` 文件，配置编译选项。
7. 或者通过命令行构建：
   ```bash
   qmake AsulCFGManager.pro
   make
   ```

### 运行程序

在构建完成后，执行生成的可执行文件以启动程序。

## 使用说明

1. 启动 Re-AsulCFGManager。
2. 点击"导入配置"，选择准备好的 CS2 安装包。
3. 工具将自动解析并将配置文件复制至游戏配置目录。
4. 利用界面功能快速切换和应用所需配置。

## 项目结构

- **Sources/**：包含所有源代码文件。
- **Headers/**：存放项目头文件。
- **Tools/**：附加工具和实用程序。
- **lib/**：依赖库和外部资源。
- **Resources/**：包含图标和其他静态资源。
- **FluentCSRM.pro**：项目的 Qt 工程文件，定义构建设置。

## 贡献指南

欢迎社区参与！如果您希望贡献代码或提出改进建议，请：

1. Fork 本项目。
2. 创建新分支进行更改。
3. 提交 Pull Request，描述您的更改和改进。

## 联系信息

如有问题或建议，请通过 [Issues](https://github.com/Asultop/AsulCFGManager/issues) 联系我们。


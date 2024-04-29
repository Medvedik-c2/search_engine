**'Описание проекта "Поисковый движок на основе инвертированного индекса"'**

Этот проект представляет собой реализацию поискового движка на основе инвертированного индекса. 
Движок разработан для чтения, индексации и поиска в коллекции документов по определенным словам. 
Проект реализован на C++ и использует многопоточность для эффективной индексации и поиска.

**'Технологии'**

* C++
* Google Test для модульного тестирования
* Многопоточность

**'Как запустить проект локально'**

* Клонируйте репозиторий.
* Перейдите в директорию проекта.
* Скомпилируйте проект с помощью предоставленного makefile.
* Запустите исполняемый файл.
* Программа запросит путь к JSON-файлам, содержащим в себе документы для индексации и поисковые запросы.

**'Структура проекта'**

Проект состоит из нескольких классов, каждый из которых отвечает за определенную функциональность:
* ConverterJSON: отвечает за чтение и преобразование JSON-файлов.
* InvertedIndex: реализует структуру данных инвертированного индекса и предоставляет функции для индексации и подсчета частоты.
* SearchServer: обрабатывает поисковые запросы и рассчитывает релевантность документов.

**'Тестирование'**
  
Проект включает в себя всеобъемлющий набор модульных тестов, реализованных с использованием Google Test.
Репозиторий GitHub
Проект размещен на GitHub. Не стесняйтесь проверить его и внести свой вклад.

CREATE TABLE users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    firstname TEXT NOT NULL,
    lastname TEXT NOT NULL,
    username TEXT NOT NULL,
    password TEXT NOT NULL
);


CREATE TABLE Fin_types(
    ID INTEGER PRIMARY KEY AUTOINCREMENT,
    Type TEXT NOT NULL,
    Description TEXT NOT NULL
);

CREATE TABLE Fin_records(
    ID INTEGER PRIMARY KEY AUTOINCREMENT,
    Amont INTEGER,
    Description TEXT NOT NULL
    Date TEXT NOT NULL
    UserID INTEGER NOT NULL,
    FinTypeID
    FOREIGN KEY (UserID) REFERENCES users(id))
    FOREIGN KEY (FinTypeID) REFERENCES fin_types Fin_types(ID));"



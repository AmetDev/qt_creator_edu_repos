CREATE TABLE Otdel (
    id_otdel INTEGER PRIMARY KEY AUTOINCREMENT,
    id_worker INTEGER,
    id_position INTEGER,
    name_otdel TEXT,
    name_position_combox TEXT,
    worker_fullname_combox TEXT,
    data_join_job DATE,
    data_remove_job DATE,
    salary_combox INTEGER,
    FOREIGN KEY(id_worker) REFERENCES Workers(id_worker),
    FOREIGN KEY(id_position) REFERENCES Position(id_position)
);

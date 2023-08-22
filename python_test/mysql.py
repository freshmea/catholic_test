import pymysql
import time

class Connection:
    def __init__(self):
        self.host    = '34.16.37.20'
        self.user    = 'guest'
        self.pw      = '1q2w3e4r'
        self.db      = 'new_schema'
        self.conn    = pymysql.connect(host=self.host, user=self.user, password=self.pw, database=self.db, charset='utf8')
        self.cur     = self.conn.cursor(pymysql.cursors.DictCursor)

        print('[알림][DB에 성공적으로 연결되었습니다.]')

    def __del__(self):
        self.conn.close()
        print('[알림][DB 연결을 끊었습니다.]')

    def getConnection(self):
        self.conn.ping()
        return self.conn, self.cur

    def insert(self):
        sql = "INSERT INTO student (name, kor, eng, math, science) VALUES (%s, %s, %s, %s, %s)"
        self.cur.execute(sql, ('choi', '100', '100', '100', '100'))
        self.conn.commit()

    def select(self):
        sql = "SELECT * FROM student where name = %s"
        self.cur.execute(sql, ("choi"))
        res = self.cur.fetchall()
        for data in res:
            print(data)

    def update(self):
        sql = "UPDATE student SET kor = %s WHERE name = %s"
        self.cur.execute(sql, ("80", "choi"))


connection = Connection()
connection.insert()
connection.update()
connection.select()

time.sleep(5)
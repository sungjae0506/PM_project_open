# PM_project_open

구현 완료
1. image
2. image_loader
3. object
4. range

구현 중
1. entity
2. player
3. read_map
4. window

구현 예정
1. map
2. sound_loader
3. sound
4. page
5. bubble
6. enemy
7. game

---

세부 설명
image: 이미지 출력

예시) Image image("snu.png", Range(0, 0, 100, 100)), image.draw()

image_loader: 이미지 로딩 (image 클래스에서 자동으로 호출해서 로딩함)

object: Point, Circle, Line, Lines 와 같은 도형 클래스

collisionDetection() 함수로 충돌 감지

range: 직사각형 범위 저장 클래스

예시) Range(0, 0, 100, 100)은 (0, 0)이 좌하단, (100, 100)이 우상단 점이 됨

---

entity: 움직이는 물체 (Player, Enemy, Bubble ...) 의 부모 클래스

위치, 속도, 가속도 등 기본적인 사항을 저장

player: 플레이어의 정보 저장 클래스 (Entity로부터 상속)

read_map: 맵 읽어들임 (추후 json 파서 구현 예정)

window: 창 정보 저장 및 함수 바인딩

---

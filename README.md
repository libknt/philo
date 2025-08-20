# Philosophers

## 概要
哲学者の夕食問題は、古典的な同期問題です。

## 参考

- [Race Condition - Wikipedia](https://en.wikipedia.org/wiki/Race_condition)
- [Deadlock - Wikipedia](https://en.wikipedia.org/wiki/Deadlock)
- [Dining_philosophers_problem - Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
---

哲学者たちには、食事を調和させ、飢餓の悲劇を避けることが重要です！

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### 1\. `number_of_philosophers`
- シミュレーションに参加する哲学者の人数です。この値は、同時にテーブルに置かれるフォークの数と同じになります。

### 2\. `time_to_die`
- ミリ秒単位の時間です。各哲学者は、最後の食事を開始した瞬間から（またはシミュレーション開始時から）この時間内に次の食事を始めないと、餓死してしまいます。

### 3\. `time_to_eat`
- ミリ秒単位の時間です。哲学者が食事をするのにかかる時間を表します。食事中、哲学者は2本のフォークを保持し続けます。

### 4\. `time_to_sleep`
- ミリ秒単位の時間です。哲学者が眠る時間を表します。

### 5\. `[number_of_times_each_philosopher_must_eat]` (任意)
- この引数は任意です。もし指定された場合、全ての哲学者が少なくともこの回数だけ食事を終えると、シミュレーションは停止します。この引数が指定されない場合は、誰か一人の哲学者が死亡した時点でシミュレーションが停止します。

### example
```bash
./philo 5 800 200 200
./philo 5 800 300 200
./philo 5 800 200 200 10
```
package RedPackage;

import java.util.Random;

/**
 * 微信红包生成算法
 * <p>
 * 2018年做了一个基于微信摇一摇的抽奖功能，后台可以配置参与抽奖的奖品，可以是微信红包、卡券（满减券、实物券）、积分
 * 将微信红包加到奖池时需要先生成好，支持等金额生成和非等金额生成，例如：20元生成10个红包，每个红包的金额固定是2元，这叫等金额生成
 * 红包生成好之后放到Redis中，并与某个奖池绑定
 * <p>
 */
public class RedPackage {
    //红包总数量
    public int totalNumber;
    //要发多大的红包，这里是200（元）
    public double totalAmount;

    public RedPackage() {
        this.totalNumber = 20;
        this.totalAmount = 200;
    }

    public static void main(String[] args) {
        RedPackage redPackageInstance = new RedPackage();
        while (true) {
            if (redPackageInstance.totalNumber > 0) {
                //每次生成一个红包可以给这个红包分配一个ticket作为这个红包的唯一标识
                double getMoney = RedPackage.getRandomMoney(redPackageInstance);
                System.out.println(getMoney);
            } else {
                System.out.println("ok!");
                System.exit(1);
            }
        }
    }

    /**
     * 生产一个红包
     */
    public static double getRandomMoney(RedPackage redPackage) {
        if (redPackage.totalNumber == 1) {
            redPackage.totalNumber--;
            return (double) Math.round(redPackage.totalAmount * 100) / 100;
        }

        Random r = new Random();
        //初始化每个红包最小金额
        double min = 0.01;
        //每个红包的最大金额：平均金额 * 2
        double max = redPackage.totalAmount / redPackage.totalNumber * 2;
        //nextDouble 返回一个大于或等于 0.0 且小于 1.0 的随机浮点数
        double money = r.nextDouble() * max;
        money = money <= min ? 0.01 : money;
        money = Math.floor(money * 100) / 100;

        //红包数减1
        redPackage.totalNumber--;
        //总金额减去当前红包的金额
        redPackage.totalAmount -= money;
        return money;
    }
}



#ifndef SHIPMANAGER_H
#define SHIPMANAGER_H

#include <vector>
#include <unordered_map>
#include "Ship.h"
#include <utility>

struct PairHash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2>& pair) const {
        std::size_t h1 = std::hash<T1>{}(pair.first);
        std::size_t h2 = std::hash<T2>{}(pair.second);
        return h1 ^ (h2 << 1);
    }
};

class ShipManager {
public:
    struct ShipInfo {
        Ship ship;
        std::unordered_map<std::pair<int, int>, int, PairHash> positionToSegmentIndex;

        ShipInfo(Ship&& ship, const std::vector<std::pair<int, int>>& positions);

        ShipInfo(const ShipInfo&) = default;
        ShipInfo& operator=(const ShipInfo&) = default;

        ShipInfo(ShipInfo&&) noexcept = default;
        ShipInfo& operator=(ShipInfo&&) noexcept = default;
    };

    ShipManager() = default;
    ShipManager(int numShips, const std::vector<int>& shipSizes);

    void addShip(Ship&& ship, const std::vector<std::pair<int, int>>& positions);
    void attackShip(int x, int y, int damage = 1);
    bool allShipsDestroyed() const;
    Ship::SegmentState getSegmentStateAt(int x, int y) const;
    bool isShipSegmentDamaged(int x, int y) const;
    bool isShipSegmentDestroyed(int x, int y) const;
    bool isShipSunkAt(int x, int y) const;
    void randomAttack();

private:
    std::vector<ShipInfo> ships_;
    int numShips_ = 0;
    std::vector<int> shipSizes_;
};

#endif // SHIPMANAGER_H
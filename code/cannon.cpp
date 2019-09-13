#include "cannon.h"

// 0: horizontal
// 1: vertical
// 2: away from origin
// 3: towards origin

int orientation(CANNON c){
  coord f = get<0>(c);
  coord s = get<1>(c);
  coord t = get<2>(c);
  int num = f.x - t.x;
  int den = f.y - t.y;
  cout<<num<<" "<<den<<"\n";
  if (num == 0){
    return 0;
  } else if (den == 0){
    return 1;
  } else{
    return (int)((((float)(num/den))/2)+2.5);
  }
}


vector<MOVE> cannon_coord_to_action(coord soldier, vector<coord> moves,bool shot){
  vector<MOVE> mvs ;
  for (int k = 0; k < moves.size(); k++){
    coord curr_coord = moves[k];
    MOVE tmp;
    if (shot == true){
      tmp = make_tuple('S',soldier.x,soldier.y,'B',curr_coord.x,curr_coord.y);
    }else{
      tmp = make_tuple('S',soldier.x,soldier.y,'M',curr_coord.x,curr_coord.y);
    }
    mvs.push_back(tmp);
  }
  return mvs;
}


vector<MOVE> cannon_shot(vector<CANNON> cannon_list,vector<coord> soldier_list, vector<coord> opp_soldier_list){
  vector<MOVE> possibilities;
  vector<coord> all_soldiers;
  all_soldiers.insert(all_soldiers.end(),soldier_list.begin(),soldier_list.end());
  all_soldiers.insert(all_soldiers.end(),opp_soldier_list.begin(),opp_soldier_list.end());

  for (int i = 0;i < cannon_list.size(); i++){
    CANNON curr_cannon = cannon_list[i];
    vector<coord> shots;
    coord f = get<0>(curr_cannon);
    coord s = get<1>(curr_cannon);
    coord t = get<2>(curr_cannon);
    int orie = orientation(curr_cannon);
    coord lb,rb,shot1,shot2;
    if (orie == 0){
      lb.x = s.x - 2;
      rb.x = s.x + 2;
      lb.y = rb.y = s.y;
      if (contains(lb,all_soldiers) == false){
        shot1.x = s.x - 3;
        shot2.x = s.x - 4;
        shot1.y = shot2.y = s.y;
        shots.push_back(shot1);
        shots.push_back(shot2);
      }
      if (contains(rb,all_soldiers) == false){
        shot1.x = s.x + 3;
        shot2.x = s.x + 4;
        shot1.y = shot2.y = s.y;
        shots.push_back(shot1);
        shots.push_back(shot2);
      }
    }else if (orie == 1){
      lb.y = s.y - 2;
      rb.y = s.y + 2;
      lb.x = rb.x = s.x;
      if (contains(lb,all_soldiers) == false){
        shot1.y = s.y - 3;
        shot2.y = s.y - 4;
        shot1.x = shot2.x = s.x;
        shots.push_back(shot1);
        shots.push_back(shot2);
      }
      if (contains(rb,all_soldiers) == false){
        shot1.y = s.y + 3;
        shot2.y = s.y + 4;
        shot1.x = shot2.x = s.x;
        shots.push_back(shot1);
        shots.push_back(shot2);
      }

    }else if (orie == 2){
      lb.x = s.x - 2;
      rb.x = s.x + 2;
      lb.y = s.y + 2;
      rb.y = s.y - 2;
      if (contains(lb,all_soldiers) == false){
        shot1.x = s.x - 3;
        shot2.x = s.x - 4;
        shot1.y = s.y + 3;
        shot2.y = s.y + 4;
        shots.push_back(shot1);
        shots.push_back(shot2);
      }
      if (contains(rb,all_soldiers) == false){
        shot1.x = s.x + 3;
        shot2.x = s.x + 4;
        shot1.y = s.y - 3;
        shot2.y = s.y - 4;
        shots.push_back(shot1);
        shots.push_back(shot2);
      }

    }else{
      lb.x = s.x - 2;
      rb.x = s.x + 2;
      lb.y = s.y - 2;
      rb.y = s.y + 2;
      if (contains(lb,all_soldiers) == false){
        shot1.x = s.x - 3;
        shot2.x = s.x - 4;
        shot1.y = s.y - 3;
        shot2.y = s.y - 4;
        shots.push_back(shot1);
        shots.push_back(shot2);
      }
      if (contains(rb,all_soldiers) == false){
        shot1.x = s.x + 3;
        shot2.x = s.x + 4;
        shot1.y = s.y + 3;
        shot2.y = s.y + 4;
        shots.push_back(shot1);
        shots.push_back(shot2);
      }
    }
    vector<coord> filter_shots = moves_filter(shots,soldier_list);
    vector<MOVE> cannon_shots = cannon_coord_to_action(s,filter_shots);
    possibilities.insert(possibilities.end(),cannon_shots.begin(),cannon_shots.end());
  }
return possibilities;
}

// 성공 부분 구현




// 라운드 클리어에 성공했음을 알리는 함수
bool success(){
    return true;
}



// 라운드별로 획득할 점수에 해당되었는지 확인하는 함수 
bool issuccess(int roundpoint,int countpoint){
    if (roundpoint<countpoint){
        return true;
    }
    return false;
}


